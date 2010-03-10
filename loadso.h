#ifndef LOADSO_H
#define LOADSO_H

#include "sd_dlopen.h"

typedef void * loadso_handle_t;
typedef void * (*loadso_pointer_t) (void *);

int loadso_open     (const char *, void **);
int loadso_symbol   (void *, const char *, void **);
int loadso_function (void *, const char *, loadso_pointer_t *);
int loadso_close    (void *);

const char *loadso_error (void);
void loadso_set_error (const char *);

#if defined(LOADSO_IMPLEMENTATION)
#if defined(SD_HAVE_DLOPEN)
int loadso_dlopen_open     (const char *, void **);
int loadso_dlopen_symbol   (void *, const char *, void **);
int loadso_dlopen_function (void *, const char *, loadso_pointer_t *);
int loadso_dlopen_close    (void *);
#endif
#endif

#endif
