#define LOADSO_IMPLEMENTATION 1

#include <assert.h>
#include <stddef.h>

#include "loadso.h"

static const char *loadso_err = "no error";

const char *
loadso_error (void)
{
  assert (loadso_err != NULL);
  return loadso_err;
}

void
loadso_set_error (const char *e)
{
  assert (e != NULL);
  loadso_err = e;
}

int
loadso_function (loadso_handle_t handle, const char *symbol, loadso_pointer_t *function)
{
  assert (handle   != NULL);
  assert (symbol   != NULL);
  assert (function != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_dlopen_function (handle, symbol, function);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}

int
loadso_open (const char *file, loadso_handle_t *handle)
{
  assert (file   != NULL);
  assert (handle != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_dlopen_open (file, handle);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}

int
loadso_symbol (loadso_handle_t handle, const char *symbol, void **pointer)
{
  assert (handle  != NULL);
  assert (symbol  != NULL);
  assert (pointer != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_dlopen_symbol (handle, symbol, pointer);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}

int
loadso_close (loadso_handle_t handle)
{
  assert (handle != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_dlopen_close (handle);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
