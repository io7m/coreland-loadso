#include <assert.h>
#include <stddef.h>

#include "_sd_ptr_uint.h"
#include "loadso.h"

#if defined(SD_HAVE_DLOPEN)
static int
loadso_function_dlopen (void *handle, const char *symbol, loadso_pointer_t *function)
{
  loadso_pointer_t pointer;
  sd_ptr_uint address;

/* subvert C99 object/function pointer <-> type rules... unfortunately */
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
#endif

int
loadso_function (void *handle, const char *symbol, loadso_pointer_t *function)
{
  assert (handle   != NULL);
  assert (symbol   != NULL);
  assert (function != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_function_dlopen (handle, symbol, function);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
