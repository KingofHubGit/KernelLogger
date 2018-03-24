#include <jni.h>
#include <stdio.h>
#include "com_pax_jni_Jni.h"
#include "utils/Log.h"
#include<android/log.h>

#define TAG "dengtl-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

JNIEXPORT jstring JNICALL Java_com_pax_kernel_logger_LoggerController_getLogString(JNIEnv *env, jobject obj) {
	char data[40];
	sprintf(data,"%s %s",__DATE__,__TIME__);
	return (*env)->NewStringUTF(env, data);
}

JNIEXPORT void Java_com_pax_kernel_logger_LoggerController_loadKernelLog(
        JNIEnv* env, jobject thiz, jstring module, jint flag)
{
	int ret;
    ret = Load_Kernel_Log_toFile((char*)("/sdcard/module.txt"),
    		1,
			"S",
			1,
            flag);


    LOGD("dengtl - : Java_com_pax_kernel_logger_LoggerController_getLogString\n");

    __android_log_print(ANDROID_LOG_DEBUG, TAG ,"dengtl - ret = %d ", ret);

    __android_log_print(ANDROID_LOG_DEBUG, TAG ,"dengtl - module = %s ", module);

    __android_log_print(ANDROID_LOG_DEBUG, TAG ,"dengtl - flag = %d ", flag);

}



