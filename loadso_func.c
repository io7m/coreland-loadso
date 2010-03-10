#include <assert.h>
#include <stddef.h>

#include "_sd-ptr_uint.h"
#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int
loadso_func_dlopen (void *handle, const char *symbol, loadso_fp *func)
{
  loadso_fp pointer;
  ptr_uint address;

/* subvert C99 object/function pointer <-> type rules... unfortunately */
#if defined(HAVE_DLFUNC)
  pointer = (loadso_fp) dlfunc (handle, symbol);
  address = 0;
#else
  address = (ptr_uint) dlsym (handle, symbol);
  pointer = (loadso_fp) address;
#endif

  if (pointer == NULL) {
    loadso_set_error (dlerror());
    return 0;
  }

  *func = pointer;
  return 1;
}
#endif

int
loadso_func (void *handle, const char *symbol, loadso_fp *func)
{
  assert (handle != NULL);
  assert (symbol != NULL);
  assert (func   != NULL);

#if defined(HAVE_DLOPEN)
  return loadso_func_dlopen (handle, symbol, func);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
