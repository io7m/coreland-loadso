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
  int r = 0;

  /* Preconditions */
  assert (handle   != NULL);
  assert (symbol   != NULL);
  assert (function != NULL);

#if defined(SD_HAVE_DLOPEN)
  r = loadso_dlopen_function (handle, symbol, function);
#elif SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
  r = loadso_win32_function (handle, symbol, function);
#else
  loadso_set_error ("function not implemented on this platform");
#endif
  if (r == 0) *function = NULL;

  /* Postconditions */
  assert (r >= 0);
  assert (r <= 1);
  if (r == 1) assert (*function != NULL);
  if (r == 0) assert (*function == NULL);

  return r;
}

int
loadso_open (const char *file, loadso_handle_t *handle)
{
  int r = 0;

  /* Preconditions */
  assert (file   != NULL);
  assert (handle != NULL);

#if defined(SD_HAVE_DLOPEN)
  r = loadso_dlopen_open (file, handle);
#elif SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
  r = loadso_win32_open (file, handle);
#else
  loadso_set_error ("function not implemented on this platform");
#endif
  if (r == 0) *handle = NULL;

  /* Postconditions */
  assert (r >= 0);
  assert (r <= 1);
  if (r == 1) assert (*handle != NULL);
  if (r == 0) assert (*handle == NULL);

  return r;
}

int
loadso_symbol (loadso_handle_t handle, const char *symbol, void **pointer)
{
  int r = 0;

  /* Preconditions */
  assert (handle  != NULL);
  assert (symbol  != NULL);
  assert (pointer != NULL);

#if defined(SD_HAVE_DLOPEN)
  r = loadso_dlopen_symbol (handle, symbol, pointer);
#elif SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
  r = loadso_win32_symbol (handle, symbol, pointer);
#else
  loadso_set_error ("function not implemented on this platform");
#endif
  if (r == 0) *pointer = NULL;

  /* Postconditions */
  assert (r >= 0);
  assert (r <= 1);
  if (r == 1) assert (*pointer != NULL);
  if (r == 0) assert (*pointer == NULL);

  return r;
}

int
loadso_close (loadso_handle_t *handle)
{
  int r = 0;

  /* Preconditions */
  assert (handle != NULL);

#if defined(SD_HAVE_DLOPEN)
  r = loadso_dlopen_close (*handle);
#elif SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
  r = loadso_win32_close (*handle);
#else
  loadso_set_error ("function not implemented on this platform");
#endif
  if (r == 1) *handle = NULL;

  /* Postconditions */
  assert (r >= 0);
  assert (r <= 1);
  if (r == 1) assert (*handle == NULL);
  if (r == 0) assert (*handle != NULL);

  return r;
}
