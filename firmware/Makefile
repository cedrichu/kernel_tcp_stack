#
# kbuild file for firmware/
#

# Create $(fwabs) from $(CONFIG_EXTRA_FIRMWARE_DIR) -- if it doesn't have a
# leading /, it's relative to $(srctree).
fwdir := $(subst ",,$(CONFIG_EXTRA_FIRMWARE_DIR))
fwabs := $(addprefix $(srctree)/,$(filter-out /%,$(fwdir)))$(filter /%,$(fwdir))

fw-external-y := $(subst ",,$(CONFIG_EXTRA_FIRMWARE))

# There are three cases to care about:
# 1. Building kernel with CONFIG_FIRMWARE_IN_KERNEL=y -- $(fw-shipped-y) should
#    include the firmware files to include, according to .config
# 2. 'make modules_install', which will install firmware for modules, and 
#    _also_ for the in-kernel drivers when CONFIG_FIRMWARE_IN_KERNEL=n
# 3. 'make firmware_install', which installs all firmware, unconditionally.

# For the former two cases we want $(fw-shipped-y) and $(fw-shipped-m) to be
# accurate. In the latter case it doesn't matter -- it'll use $(fw-shipped-all).
# But be aware that the config file might not be included at all.

fw-shipped-$(CONFIG_BNX2X) += bnx2x/bnx2x-e1-7.8.17.0.fw \
			      bnx2x/bnx2x-e1h-7.8.17.0.fw \
			      bnx2x/bnx2x-e2-7.8.17.0.fw
fw-shipped-$(CONFIG_BNX2) += 	bnx2/bnx2-mips-09-6.2.1b.fw \
				bnx2/bnx2-rv2p-06-6.0.15.fw \
				bnx2/bnx2-mips-06-6.2.3.fw \
				bnx2/bnx2-rv2p-09-6.0.17.fw \
				bnx2/bnx2-rv2p-09ax-6.0.17.fw
fw-shipped-$(CONFIG_ADAPTEC_STARFIRE) += adaptec/starfire_rx.bin \
					 adaptec/starfire_tx.bin
fw-shipped-$(CONFIG_E100) += e100/d101m_ucode.bin e100/d101s_ucode.bin \
			     e100/d102e_ucode.bin
fw-shipped-$(CONFIG_PCMCIA_PCNET) += 
				     
fw-shipped-$(CONFIG_PCMCIA_3C589) += 
fw-shipped-$(CONFIG_PCMCIA_3C574) += 
fw-shipped-$(CONFIG_SERIAL_8250_CS) +=
				       
fw-shipped-$(CONFIG_SCSI_ADVANSYS) += advansys/mcode.bin advansys/38C1600.bin \
				      advansys/3550.bin advansys/38C0800.bin
fw-shipped-$(CONFIG_SCSI_QLOGIC_1280) += qlogic/1040.bin qlogic/1280.bin \
					 qlogic/12160.bin
fw-shipped-$(CONFIG_SCSI_QLOGICPTI) += qlogic/isp1000.bin
fw-shipped-$(CONFIG_INFINIBAND_QIB) += qlogic/sd7220.fw
fw-shipped-$(CONFIG_SND_KORG1212) += korg/k1212.dsp
fw-shipped-$(CONFIG_SND_SB16_CSP) += sb16/mulaw_main.csp sb16/alaw_main.csp \
				     sb16/ima_adpcm_init.csp \
				     sb16/ima_adpcm_playback.csp \
				     sb16/ima_adpcm_capture.csp
fw-shipped-$(CONFIG_SND_WAVEFRONT) += yamaha/yss225_registers.bin
fw-shipped-$(CONFIG_TIGON3) += tigon/tg3.bin tigon/tg3_tso.bin \
			       tigon/tg3_tso5.bin
fw-shipped-$(CONFIG_TYPHOON) += 3com/typhoon.bin
fw-shipped-$(CONFIG_USB_EMI26) += emi26/loader.fw emi26/firmware.fw \
				  emi26/bitstream.fw
fw-shipped-$(CONFIG_USB_EMI62) += emi62/loader.fw emi62/bitstream.fw \
				  emi62/spdif.fw emi62/midi.fw
fw-shipped-$(CONFIG_USB_SERIAL_WHITEHEAT) += whiteheat_loader.fw whiteheat.fw \
					   # whiteheat_loader_debug.fw

fw-shipped-$(CONFIG_BT_ATH3K) += ath3k-1.fw

fw-shipped-$(CONFIG_ATH6KL) += \
	ath6k/AR6003/hw2.1.1/fw-3.bin \
	ath6k/AR6003/hw2.1.1/bdata.SD31.bin \
	ath6k/AR6003/hw2.1.1/athwlan.bin \
	ath6k/AR6003/hw2.1.1/otp.bin \
	ath6k/AR6003/hw2.1.1/data.patch.bin \
	ath6k/AR6003/hw2.1.1/fw-2.bin \
	ath6k/AR6003/hw2.0/bdata.SD31.bin \
	ath6k/AR6003/hw2.0/athwlan.bin.z77 \
	ath6k/AR6003/hw2.0/otp.bin.z77 \
	ath6k/AR6003/hw2.0/data.patch.bin \
	ath6k/AR6004/hw1.2/bdata.bin \
	ath6k/AR6004/hw1.2/fw-2.bin \
	ath6k/AR6004/hw1.3/fw-3.bin \
	ath6k/AR6004/hw1.3/bdata.bin

fw-shipped-$(CONFIG_RTLWIFI) += \
	rtlwifi/rtl8192cfwU.bin \
	rtlwifi/rtl8192cfwU_B.bin \
	rtlwifi/rtl8192defw.bin \
	rtlwifi/rtl8192sefw.bin \
	rtlwifi/rtl8712u.bin

fw-shipped-$(CONFIG_WL12XX) += \
	ti-connectivity/wl18xx-fw.bin \
	ti-connectivity/wl127x-fw-5-plt.bin \
	ti-connectivity/wl128x-fw-5-sr.bin \
	ti-connectivity/wl128x-fw-5-mr.bin \
	ti-connectivity/wl128x-fw-5-plt.bin \
	ti-connectivity/wl127x-fw-5-mr.bin \
	ti-connectivity/wl127x-fw-5-sr.bin

fw-shipped-$(CONFIG_SCSI_QLA_FC) += \
	ql2300_fw.bin \
	ql2322_fw.bin \
	ql2400_fw.bin \
	ql2500_fw.bin

fw-shipped-$(CONFIG_DRM_RADEON) += \
	radeon/TAHITI_mc.bin	\
	radeon/VERDE_me.bin	\
	radeon/ARUBA_me.bin	\
	radeon/VERDE_pfp.bin	\
	radeon/PITCAIRN_ce.bin	\
	radeon/TAHITI_ce.bin	\
	radeon/TAHITI_pfp.bin	\
	radeon/PITCAIRN_pfp.bin	\
	radeon/TAHITI_rlc.bin	\
	radeon/ARUBA_rlc.bin	\
	radeon/ARUBA_pfp.bin	\
	radeon/VERDE_ce.bin	\
	radeon/VERDE_mc.bin	\
	radeon/PITCAIRN_rlc.bin	\
	radeon/PITCAIRN_me.bin	\
	radeon/VERDE_rlc.bin	\
	radeon/PITCAIRN_mc.bin	\
	radeon/TAHITI_me.bin

fw-shipped-$(CONFIG_R8169) +=	\
	rtl_nic/rtl8168f-1.fw	\
	rtl_nic/rtl8411-1.fw	\
	rtl_nic/rtl8168g-1.fw	\
	rtl_nic/rtl8106e-1.fw

fw-shipped-$(CONFIG_SND_ASIHPI) += \
	asihpi/dsp5000.bin \
	asihpi/dsp6200.bin \
	asihpi/dsp6205.bin \
	asihpi/dsp6400.bin \
	asihpi/dsp6600.bin \
	asihpi/dsp8700.bin \
	asihpi/dsp8900.bin

fw-shipped-$(CONFIG_AR5523) += ar5523.bin

fw-shipped-$(CONFIG_LIBERTAS) += libertas/sd8686_v9.bin

fw-shipped-$(CONFIG_NETXEN_NIC) += phanfw.bin

fw-shipped-$(CONFIG_MWIFIEX) += \
	mrvl/usb8797_uapsta.bin \
	mrvl/sd8787_uapsta.bin \
	mrvl/sd8797_uapsta.bin

fw-shipped-$(CONFIG_CARL9170) += carl9170-1.fw

fw-shipped-$(CONFIG_BRCMSMAC) += \
	brcm/bcm43xx_hdr-0.fw \
	brcm/bcm43xx-0.fw

fw-shipped-$(CONFIG_SND_HDA_CODEC_CA0132_DSP) += \
	ctefx.bin

fw-shipped-$(CONFIG_VIDEO_GO7007) +=	\
	go7007/go7007fw.bin		\
	go7007/go7007tv.bin		\
	go7007/lr192.fw			\
	go7007/px-m402u.fw		\
	go7007/px-tv402u.fw		\
	go7007/s2250-1.fw		\
	go7007/s2250-2.fw		\
	go7007/wis-startrek.fw

fw-shipped-$(CONFIG_MWIFIEX) += 	\
	mrvl/pcie8897_uapsta.bin	\
	mrvl/sd8688.bin			\
	mrvl/sd8688_helper.bin

fw-shipped-$(CONFIG_DRM_RADEON) +=	\
	radeon/BARTS_smc.bin		\
	radeon/BONAIRE_ce.bin		\
	radeon/BONAIRE_mc.bin		\
	radeon/BONAIRE_me.bin		\
	radeon/BONAIRE_mec.bin		\
	radeon/BONAIRE_pfp.bin		\
	radeon/BONAIRE_rlc.bin		\
	radeon/BONAIRE_sdma.bin		\
	radeon/BONAIRE_uvd.bin		\
	radeon/CAICOS_smc.bin		\
	radeon/CAYMAN_smc.bin		\
	radeon/CEDAR_smc.bin		\
	radeon/CYPRESS_smc.bin		\
	radeon/CYPRESS_uvd.bin		\
	radeon/HAINAN_ce.bin		\
	radeon/HAINAN_mc.bin		\
	radeon/HAINAN_me.bin		\
	radeon/HAINAN_pfp.bin		\
	radeon/HAINAN_rlc.bin		\
	radeon/HAINAN_smc.bin		\
	radeon/JUNIPER_smc.bin		\
	radeon/KABINI_ce.bin		\
	radeon/KABINI_me.bin		\
	radeon/KABINI_mec.bin		\
	radeon/KABINI_pfp.bin		\
	radeon/KABINI_rlc.bin		\
	radeon/KABINI_sdma.bin		\
	radeon/OLAND_ce.bin		\
	radeon/OLAND_mc.bin		\
	radeon/OLAND_me.bin		\
	radeon/OLAND_pfp.bin		\
	radeon/OLAND_rlc.bin		\
	radeon/OLAND_smc.bin		\
	radeon/PITCAIRN_smc.bin		\
	radeon/REDWOOD_smc.bin		\
	radeon/RV710_smc.bin		\
	radeon/RV710_uvd.bin		\
	radeon/RV730_smc.bin		\
	radeon/RV740_smc.bin		\
	radeon/RV770_smc.bin		\
	radeon/SUMO_uvd.bin		\
	radeon/TAHITI_smc.bin		\
	radeon/TAHITI_uvd.bin		\
	radeon/TURKS_smc.bin		\
	radeon/VERDE_smc.bin

fw-shipped-$(CONFIG_R8169) +=	\
	rtl_nic/rtl8106e-2.fw	\
	rtl_nic/rtl8168g-2.fw	\
	rtl_nic/rtl8168g-3.fw	\
	rtl_nic/rtl8411-2.fw

fw-shipped-$(CONFIG_RTLWIFI) += \
	rtlwifi/rtl8188efw.bin

fw-shipped-$(CONFIG_WL12XX) += \
	ti-connectivity/wl18xx-fw-2.bin

fw-shipped-$(CONFIG_USB_BTMTK) += \
	mt7650.bin

fw-shipped-$(CONFIG_MWL8K) += \
	mwl8k/fmimage_8366_ap-3.fw

fw-shipped-$(CONFIG_SERIAL_RP2) += \
	rp2.fw

fw-shipped-m += rt3290.bin

fw-shipped-m += \
	amd-ucode/microcode_amd.bin \
	amd-ucode/microcode_amd_fam15h.bin

fw-shipped-$(CONFIG_BT_ATH3K) += \
	ar3k/AthrBT_0x31010000.dfu \
	ar3k/ramps_0x31010000_40.dfu

fw-shipped-$(CONFIG_ATH10K) += \
	ath10k/QCA988X/hw2.0/board.bin \
	ath10k/QCA988X/hw2.0/firmware.bin \
	ath10k/QCA988X/hw2.0/otp.bin

fw-shipped-all := $(fw-shipped-y) $(fw-shipped-m) $(fw-shipped-)

# Directories which we _might_ need to create, so we have a rule for them.
firmware-dirs := $(sort $(addprefix $(objtree)/$(obj)/,$(dir $(fw-external-y) $(fw-shipped-all))))

quiet_cmd_mkdir = MKDIR   $(patsubst $(objtree)/%,%,$@)
      cmd_mkdir = mkdir -p $@

quiet_cmd_ihex  = IHEX    $@
      cmd_ihex  = $(OBJCOPY) -Iihex -Obinary $< $@

quiet_cmd_ihex2fw  = IHEX2FW $@
      cmd_ihex2fw  = $(objtree)/$(obj)/ihex2fw $< $@

quiet_cmd_h16tofw  = H16TOFW $@
      cmd_h16tofw  = $(objtree)/$(obj)/ihex2fw -w $< $@

quiet_cmd_fwbin = MK_FW   $@
      cmd_fwbin = FWNAME="$(patsubst firmware/%.gen.S,%,$@)";		     \
		  FWSTR="$(subst /,_,$(subst .,_,$(subst -,_,$(patsubst	     \
				firmware/%.gen.S,%,$@))))";		     \
		  ASM_WORD=$(if $(CONFIG_64BIT),.quad,.long);		     \
		  ASM_ALIGN=$(if $(CONFIG_64BIT),3,2);			     \
		  PROGBITS=$(if $(CONFIG_ARM),%,@)progbits;		     \
		  echo "/* Generated by firmware/Makefile */"		> $@;\
		  echo "    .section .rodata"				>>$@;\
		  echo "    .p2align $${ASM_ALIGN}"			>>$@;\
		  echo "_fw_$${FWSTR}_bin:"				>>$@;\
		  echo "    .incbin \"$(2)\""				>>$@;\
		  echo "_fw_end:"					>>$@;\
		  echo "   .section .rodata.str,\"aMS\",$${PROGBITS},1"	>>$@;\
		  echo "    .p2align $${ASM_ALIGN}"			>>$@;\
		  echo "_fw_$${FWSTR}_name:"				>>$@;\
		  echo "    .string \"$$FWNAME\""			>>$@;\
		  echo "    .section .builtin_fw,\"a\",$${PROGBITS}"	>>$@;\
		  echo "    .p2align $${ASM_ALIGN}"			>>$@;\
		  echo "    $${ASM_WORD} _fw_$${FWSTR}_name"		>>$@;\
		  echo "    $${ASM_WORD} _fw_$${FWSTR}_bin"		>>$@;\
		  echo "    $${ASM_WORD} _fw_end - _fw_$${FWSTR}_bin"	>>$@;

# One of these files will change, or come into existence, whenever
# the configuration changes between 32-bit and 64-bit. The .S files
# need to change when that happens.
wordsize_deps := $(wildcard include/config/64bit.h include/config/32bit.h \
		include/config/ppc32.h include/config/ppc64.h \
		include/config/superh32.h include/config/superh64.h \
		include/config/x86_32.h include/config/x86_64.h)

# Workaround for make < 3.81, where .SECONDEXPANSION doesn't work.
# It'll end up depending on these targets, so make them a PHONY rule which
# depends on _all_ the directories in $(firmware-dirs), and it'll work out OK.
PHONY += $(objtree)/$$(%) $(objtree)/$(obj)/$$(%)
$(objtree)/$$(%) $(objtree)/$(obj)/$$(%): $(firmware-dirs)
	@true

# For the $$(dir %) trick, where we need % to be expanded first.
.SECONDEXPANSION:

$(patsubst %,$(obj)/%.gen.S, $(fw-shipped-y)): %: $(wordsize_deps) \
		| $(objtree)/$$(dir %)
	$(call cmd,fwbin,$(patsubst %.gen.S,%,$@))
$(patsubst %,$(obj)/%.gen.S, $(fw-external-y)): %: $(wordsize_deps) \
		include/config/extra/firmware/dir.h | $(objtree)/$$(dir %)
	$(call cmd,fwbin,$(fwabs)/$(patsubst $(obj)/%.gen.S,%,$@))

# The .o files depend on the binaries directly; the .S files don't.
$(patsubst %,$(obj)/%.gen.o, $(fw-shipped-y)): %.gen.o: %
$(patsubst %,$(obj)/%.gen.o, $(fw-external-y)): $(obj)/%.gen.o: $(fwdir)/%

# .ihex is used just as a simple way to hold binary files in a source tree
# where binaries are frowned upon. They are directly converted with objcopy.
$(obj)/%: $(obj)/%.ihex | $(objtree)/$(obj)/$$(dir %)
	$(call cmd,ihex)

$(obj)/%: $(obj)/%.dfu | $(objtree)/$(obj)/$$(dir %)
	$(call cmd,ihex)

$(obj)/%: $(obj)/%.z77 | $(objtree)/$(obj)/$$(dir %)
	$(call cmd,ihex)

# Don't depend on ihex2fw if we're installing and it already exists.
# Putting it after | in the dependencies doesn't seem sufficient when
# we're installing after a cross-compile, because ihex2fw has dependencies
# on stuff like /usr/lib/gcc/ppc64-redhat-linux/4.3.0/include/stddef.h and 
# thus wants to be rebuilt. Which it can't be, if the prebuilt kernel tree
# is exported read-only for someone to run 'make install'.
ifeq ($(INSTALL):$(wildcard $(obj)/ihex2fw),install:$(obj)/ihex2fw)
ihex2fw_dep :=
else
ihex2fw_dep := $(obj)/ihex2fw
endif

# .HEX is also Intel HEX, but where the offset and length in each record
# is actually meaningful, because the firmware has to be loaded in a certain
# order rather than as a single binary blob. Thus, we convert them into our
# more compact binary representation of ihex records (<linux/ihex.h>)
$(obj)/%.fw: $(obj)/%.HEX $(ihex2fw_dep) | $(objtree)/$(obj)/$$(dir %)
	$(call cmd,ihex2fw)

# .H16 is our own modified form of Intel HEX, with 16-bit length for records.
$(obj)/%.fw: $(obj)/%.H16 $(ihex2fw_dep) | $(objtree)/$(obj)/$$(dir %)
	$(call cmd,h16tofw)

$(firmware-dirs):
	$(call cmd,mkdir)

obj-y				 += $(patsubst %,%.gen.o, $(fw-external-y))
obj-$(CONFIG_FIRMWARE_IN_KERNEL) += $(patsubst %,%.gen.o, $(fw-shipped-y))

# Remove .S files and binaries created from ihex
# (during 'make clean' .config isn't included so they're all in $(fw-shipped-))
targets := $(fw-shipped-) $(patsubst $(obj)/%,%, \
				$(shell find $(obj) -name \*.gen.S 2>/dev/null))

# Without this, built-in.o won't be created when it's empty, and the
# final vmlinux link will fail.
obj-n := dummy

hostprogs-y := ihex2fw
