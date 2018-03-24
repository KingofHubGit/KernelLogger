#ifndef _LIBS_CUTILS_ULOG_API_H
#define _LIBS_CUTILS_ULOG_API_H

#ifdef __cplusplus
extern "C" {
#endif

extern int Load_Kernel_Log_toFile(const char *filename, char *tag, int prio,
    unsigned int flags);

#ifdef __cplusplus
}
#endif

#endif
