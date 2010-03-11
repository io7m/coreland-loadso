#ifndef LOADSO_H
#define LOADSO_H

typedef void * loadso_handle_t;
typedef void * (*loadso_pointer_t) (void *);

int loadso_open     (const char *, loadso_handle_t *);
int loadso_symbol   (loadso_handle_t, const char *, void **);
int loadso_function (loadso_handle_t, const char *, loadso_pointer_t *);
int loadso_close    (loadso_handle_t *);

const char *loadso_error (void);
void loadso_set_error (const char *);

#if defined(LOADSO_IMPLEMENTATION)
#include "_sd_sysinfo.h"
#include "_sd_dlopen.h"

#if defined(SD_HAVE_DLOPEN)
int loadso_dlopen_open     (const char *, loadso_handle_t *);
int loadso_dlopen_symbol   (loadso_handle_t, const char *, void **);
int loadso_dlopen_function (loadso_handle_t, const char *, loadso_pointer_t *);
int loadso_dlopen_close    (loadso_handle_t);
#endif /* SD_HAVE_DLOPEN */

#if SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
int loadso_win32_open     (const char *, loadso_handle_t *);
int loadso_win32_symbol   (loadso_handle_t, const char *, void **);
int loadso_win32_function (loadso_handle_t, const char *, loadso_pointer_t *);
int loadso_win32_close    (loadso_handle_t);
#endif /* SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS */

#endif /* LOADSO_IMPLEMENTATION */

#endif /* LOADSO_H */
