#ifndef LOADSO_H
#define LOADSO_H

#include "sd_dlopen.h"

typedef void * (*loadso_fp)(void *);

int loadso_open (const char *, void **);
int loadso_sym (void *, const char *, void **);
int loadso_func (void *, const char *, loadso_fp *);
int loadso_close (void *);

const char *loadso_error (void);
void loadso_set_error (const char *);

#endif
