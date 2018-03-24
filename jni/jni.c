#include <jni.h>
#include <stdio.h>
#include "com_pax_jni_Jni.h"
#include "utils/Log.h"
#include<android/log.h>

#define TAG "dengtl-jni" // ������Զ����LOG�ı�ʶ
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // ����LOGD����
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // ����LOGI����
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // ����LOGW����
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // ����LOGE����
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // ����LOGF����

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



