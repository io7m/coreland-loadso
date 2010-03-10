#define LOADSO_IMPLEMENTATION 1

#include <assert.h>
#include <stddef.h>

#include "loadso.h"

/*
 * dlopen/dlfunc
 */

#if defined(SD_HAVE_DLOPEN)
#include "_sd_ptr_uint.h"

int
loadso_dlopen_close (loadso_handle_t handle)
{
  if (dlclose (handle) != 0) {
    loadso_set_error (dlerror ());
    return 0;
  } else
    return 1;
}

int
loadso_dlopen_symbol (loadso_handle_t handle, const char *symbol, void **pointer)
{
  void *address;

  address = dlsym (handle, symbol);
  if (address == NULL) {
    loadso_set_error (dlerror());
    return 0;
  }

  *pointer = address;
  return 1;
}

int
loadso_dlopen_function (loadso_handle_t handle, const char *symbol, loadso_pointer_t *function)
{
  loadso_pointer_t pointer;
  sd_ptr_uint address;

  /* Subvert C99 object/function pointer <-> type rules, unfortunately. */
#if defined(SD_HAVE_DLFUNC)
  pointer = (loadso_pointer_t) dlfunc (handle, symbol);
  address = 0;
#else
  address = (sd_ptr_uint) dlsym (handle, symbol);
  pointer = (loadso_pointer_t) address;
#endif

  if (pointer == NULL) {
    loadso_set_error (dlerror());
    return 0;
  }

  *function = pointer;
  return 1;
}

int
loadso_dlopen_open (const char *file, void **handle)
{
  void *raw_handle;

  raw_handle = dlopen (file, RTLD_NOW);
  if (raw_handle == NULL) {
    loadso_set_error (dlerror ());
    return 0;
  }

  *handle = raw_handle;
  return 1;
}

#endif /* SD_HAVE_DLOPEN */
