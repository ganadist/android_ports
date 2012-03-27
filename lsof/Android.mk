LOCAL_PATH := $(call my-dir)
include $(CLEAR_VARS)

LOCAL_MODULE := lsof2
LOCAL_SRC_FILES := \
	dialects/linux/dfile.c \
	dialects/linux/dmnt.c \
	dialects/linux/dnode.c \
	dialects/linux/dproc.c \
	dialects/linux/dsock.c \
	dialects/linux/dstore.c \
	arg.c main.c misc.c node.c print.c proc.c store.c usage.c \
	util.c

LOCAL_SRC_FILES += \
	lib/ckkv.c lib/cvfs.c lib/dvch.c lib/fino.c lib/isfn.c lib/lkud.c lib/pdvn.c lib/prfp.c \
	lib/ptti.c lib/rdev.c lib/regex.c lib/rmnt.c lib/rnam.c lib/rnch.c lib/rnmh.c lib/snpf.c

LOCAL_CFLAGS := \
	-DLINUXV=26035 \
	-DHASIPv6 \
	-D_FILE_OFFSET_BITS=64 \
	-D_LARGEFILE64_SOURCE \
	-DHAS_STRFTIME \
	-DLSOF_VSTR=\"2.6.35\" \
	-DHASNORPC_H \
	-DUSE_LIB_REGEX \
	-DSTDC_HEADERS

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/android \
	$(LOCAL_PATH)/dialects/linux

LOCAL_MODULE_TAGS := eng

include $(BUILD_EXECUTABLE)
