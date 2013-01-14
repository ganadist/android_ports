LOCAL_PATH:= $(call my-dir)
include $(CLEAR_VARS)

# missing syscalls in bionic
LOCAL_SRC_FILES := \
	syscalls/arm_fadvise64_64.S \
	syscalls/fanotify.S \
	syscalls/inotify.S \
	syscalls/signalfd.S \
	syscalls/errno.c \
	syscalls/fadvise.c \

LOCAL_SRC_FILES += \
	shared/hashmap.c \
	shared/util.c \

LOCAL_SRC_FILES += \
	readahead-analyze.c \
	readahead-collect.c \
	readahead-common.c \
	readahead-replay.c \
	readahead.c \
	fan.c \

LOCAL_MODULE := sd_readahead
LOCAL_MODULE_TAGS := eng

LOCAL_C_INCLUDES := \
	$(LOCAL_PATH)/syscalls \
	$(LOCAL_PATH)/shared \
	$(LOCAL_PATH)/wrapper \

LOCAL_SHARED_LIBRARIES := libcutils liblog libutils

include $(BUILD_EXECUTABLE)
