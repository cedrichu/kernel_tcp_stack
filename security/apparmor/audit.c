/*
 * AppArmor security module
 *
 * This file contains AppArmor auditing functions
 *
 * Copyright (C) 1998-2008 Novell/SUSE
 * Copyright 2009-2010 Canonical Ltd.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation, version 2 of the
 * License.
 */

#include <linux/audit.h>
#include <linux/socket.h>

#include "include/apparmor.h"
#include "include/audit.h"
#include "include/policy.h"

const char *const op_table[] = {
	"null",

	"sysctl",
	"capable",

	"unlink",
	"mkdir",
	"rmdir",
	"mknod",
	"truncate",
	"link",
	"symlink",
	"rename_src",
	"rename_dest",
	"chmod",
	"chown",
	"getattr",
	"open",

	"file_perm",
	"file_lock",
	"file_mmap",
	"file_mprotect",

	"pivotroot",
	"mount",
	"umount",

	"create",
	"post_create",
	"bind",
	"connect",
	"listen",
	"accept",
	"sendmsg",
	"recvmsg",
	"getsockname",
	"getpeername",
	"getsockopt",
	"setsockopt",
	"socket_shutdown",

	"ptrace",

	"exec",
	"change_hat",
	"change_profile",
	"change_onexec",

	"setprocattr",
	"setrlimit",

	"profile_replace",
	"profile_load",
	"profile_remove"
};

const char *const audit_mode_names[] = {
	"normal",
	"quiet_denied",
	"quiet",
	"noquiet",
	"all"
};

static const char *const aa_audit_type[] = {
	"AUDIT",
	"ALLOWED",
	"DENIED",
	"HINT",
	"STATUS",
	"ERROR",
	"KILLED",
	"AUTO"
};

/*
 * Currently AppArmor auditing is fed straight into the audit framework.
 *
 * TODO:
 * netlink interface for complain mode
 * user auditing, - send user auditing to netlink interface
 * system control of whether user audit messages go to system log
 */

/**
 * audit_base - core AppArmor function.
 * @ab: audit buffer to fill (NOT NULL)
 * @ca: audit structure containing data to audit (NOT NULL)
 *
 * Record common AppArmor audit data from @sa
 */
static void audit_pre(struct audit_buffer *ab, void *ca)
{
	struct common_audit_data *sa = ca;
	struct task_struct *tsk = aad(sa)->tsk ? aad(sa)->tsk : current;

	if (aa_g_audit_header) {
		audit_log_format(ab, "apparmor=");
		audit_log_string(ab, aa_audit_type[aad(sa)->type]);
	}

	if (aad(sa)->op) {
		audit_log_format(ab, " operation=");
		audit_log_string(ab, op_table[aad(sa)->op]);
	}

	if (aad(sa)->info) {
		audit_log_format(ab, " info=");
		audit_log_string(ab, aad(sa)->info);
		if (aad(sa)->error)
			audit_log_format(ab, " error=%d", aad(sa)->error);
	}

	if (aad(sa)->label) {
		struct aa_label *label = aad(sa)->label;
		pid_t pid;
		rcu_read_lock();
		pid = rcu_dereference(tsk->real_parent)->pid;
		rcu_read_unlock();
		audit_log_format(ab, " parent=%d", pid);
		if (label_isprofile(label)) {
			struct aa_profile *profile = labels_profile(label);
			if (profile->ns != root_ns) {
				audit_log_format(ab, " namespace=");
				audit_log_untrustedstring(ab,
							  profile->ns->base.hname);
			}
			audit_log_format(ab, " profile=");
			audit_log_untrustedstring(ab, profile->base.hname);
		} else {
			audit_log_format(ab, " label=");
			aa_label_audit(ab, root_ns, label, false, GFP_ATOMIC);
		}
	}

	if (aad(sa)->name) {
		audit_log_format(ab, " name=");
		audit_log_untrustedstring(ab, aad(sa)->name);
	}

	if (aad(sa)->tsk) {
		audit_log_format(ab, " pid=%d comm=", tsk->pid);
		audit_log_untrustedstring(ab, tsk->comm);
	}

}

/**
 * aa_audit_msg - Log a message to the audit subsystem
 * @sa: audit event structure (NOT NULL)
 * @cb: optional callback fn for type specific fields (MAYBE NULL)
 */
void aa_audit_msg(int type, struct common_audit_data *sa,
		  void (*cb) (struct audit_buffer *, void *))
{
	aad(sa)->type = type;
	common_lsm_audit(sa, audit_pre, cb);
}

/**
 * aa_audit - Log a profile based audit event to the audit subsystem
 * @type: audit type for the message
 * @profile: profile to check against (NOT NULL)
 * @gfp: allocation flags to use
 * @sa: audit event (NOT NULL)
 * @cb: optional callback fn for type specific fields (MAYBE NULL)
 *
 * Handle default message switching based off of audit mode flags
 *
 * Returns: error on failure
 */
int aa_audit(int type, struct aa_profile *profile, gfp_t gfp,
	     struct common_audit_data *sa,
	     void (*cb) (struct audit_buffer *, void *))
{
	BUG_ON(!profile);

	if (type == AUDIT_APPARMOR_AUTO) {
		if (likely(!aad(sa)->error)) {
			if (AUDIT_MODE(profile) != AUDIT_ALL)
				return 0;
			type = AUDIT_APPARMOR_AUDIT;
		} else if (COMPLAIN_MODE(profile))
			type = AUDIT_APPARMOR_ALLOWED;
		else
			type = AUDIT_APPARMOR_DENIED;
	}
	if (AUDIT_MODE(profile) == AUDIT_QUIET ||
	    (type == AUDIT_APPARMOR_DENIED &&
	     AUDIT_MODE(profile) == AUDIT_QUIET))
		return aad(sa)->error;

	if (KILL_MODE(profile) && type == AUDIT_APPARMOR_DENIED)
		type = AUDIT_APPARMOR_KILL;

	aad(sa)->label = &profile->label;

	aa_audit_msg(type, sa, cb);

	if (aad(sa)->type == AUDIT_APPARMOR_KILL)
		(void)send_sig_info(SIGKILL, NULL,
				    aad(sa)->tsk ?  aad(sa)->tsk : current);

	if (aad(sa)->type == AUDIT_APPARMOR_ALLOWED)
		return complain_error(aad(sa)->error);

	return aad(sa)->error;
}
