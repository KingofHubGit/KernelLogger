LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE    := libjni_pax_dmesg
LOCAL_SRC_FILES := jni.c  jni_impl.c

LOCAL_LDLIBS :=-llog

LOCAL_SHARED_LIBRARIES := \
    libandroid_runtime \
    libnativehelper \
    libcutils \
    libutils \
    liblog \
    libhardware
    
LOCAL_MODULE_TAGS := optional

include $(BUILD_SHARED_LIBRARY)
