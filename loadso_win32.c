#define LOADSO_IMPLEMENTATION 1

#include <assert.h>
#include <stddef.h>

#include "_sd_sysinfo.h"
#include "loadso.h"

/*
 * LoadLibrary, GetProcAddress, etc. 
 */

#if SD_SYSINFO_OS == SD_SYSINFO_OS_MS_WINDOWS
#include <windows.h>
#include "_sd_ptr_uint.h"

static const char *
loadso_win32_error_message (void)
{
  static char buffer [8192];
  DWORD error_code = GetLastError ();

  if (error_code != 0) {
    FormatMessage
     (FORMAT_MESSAGE_FROM_SYSTEM,
      NULL,
      error_code,
      0,
      (LPTSTR) buffer,
      sizeof (buffer),
      0);
  } else {
    buffer [0] = 0;
  }

  return buffer;
}

int
loadso_win32_close (loadso_handle_t handle)
{
  if (FreeLibrary (handle) == 0) {
    loadso_set_error (loadso_win32_error_message ());
    return 0;
  } else
    return 1;
}

int
loadso_win32_symbol (loadso_handle_t handle, const char *symbol, void **pointer)
{
  void *address;

  address = GetProcAddress (handle, symbol);
  if (address == NULL) {
    loadso_set_error (loadso_win32_error_message ());
    return 0;
  }

  *pointer = address;
  return 1;
}

int
loadso_win32_function (loadso_handle_t handle, const char *symbol, loadso_pointer_t *function)
{
  void *address;

  address = GetProcAddress (handle, symbol);
  if (address == NULL) {
    loadso_set_error (loadso_win32_error_message ());
    return 0;
  }

  *function = address;
  return 1;
}

int
loadso_win32_open (const char *file, loadso_handle_t *handle)
{
  HMODULE *raw_handle;

  raw_handle = LoadLibrary (file);
  if (raw_handle == NULL) {
    loadso_set_error (loadso_win32_error_message ());
    return 0;
  }

  *handle = raw_handle;
  return 1;
}

#endif /* SD_SYSINFO_OS_MS_WINDOWS */
