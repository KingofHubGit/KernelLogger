#define LOG_TAG "ULog"

#include <time.h>
#include <stdio.h>
#ifdef HAVE_PTHREADS
#include <pthread.h>
#endif
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>

//#include <cutils/logd.h>
#include <cutils/log.h>
#include <android/log.h>
//#include <cutils/uio.h>

//#include <cutils/ulog.h>
//#include <cutils/ulog_api.h>

//#include "ulog.h"
//#include "ulog_api.h"


#include <linux/ashmem.h>
#include <cutils/ashmem.h>
#include <unistd.h>
#include <sys/mman.h>
#include <poll.h>
#include <sys/klog.h>
#include<android/log.h>

#define TAG "dengtl-jni" // 这个是自定义的LOG的标识
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG,TAG ,__VA_ARGS__) // 定义LOGD类型
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO,TAG ,__VA_ARGS__) // 定义LOGI类型
#define LOGW(...) __android_log_print(ANDROID_LOG_WARN,TAG ,__VA_ARGS__) // 定义LOGW类型
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,TAG ,__VA_ARGS__) // 定义LOGE类型
#define LOGF(...) __android_log_print(ANDROID_LOG_FATAL,TAG ,__VA_ARGS__) // 定义LOGF类型

#ifdef __cplusplus

extern "C" {
#endif


/* =====================APIs===========================  */
int Load_Kernel_Log_toFile(char *filename, int type,
    char *type_name,  unsigned int mask, unsigned int flags)
{
    int fd;
    int ret = 555;
    /*ddebug_cfg cfg;

    fd = open(DEV_NODE_PATH, O_RDWR);
    if (fd < 0) {
        perror("open error:\r\n");
        return -1;
    }
    cfg.debug_level = mask;
    cfg.filename = filename;
    cfg.type = type;
    cfg.type_name = type_name;
    cfg.flags = flags;

    ret = ioctl(fd, IOCTL_UDEBUG_ADD_TAG, &cfg);
    if (ret < 0) {
        close(fd);
        return ret;
    }

    if (type != DDEBUG_TYPE_MODULE)
        ret = __open_dynamic_debug_control(type, type_name);

    close(fd);*/
    LOGD("dengtl - : Load_Kernel_Log_toFile\n");
    return ret;
}

#ifdef __cplusplus
}
#endif
