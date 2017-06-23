LOCAL_PATH := $(call my-dir)
 
include $(CLEAR_VARS)
 
LOCAL_MODULE    := MyNdkTest
LOCAL_SRC_FILES := MyNdkTest.c
 
include $(BUILD_SHARED_LIBRARY)
