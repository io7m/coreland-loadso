#include <assert.h>
#include <stddef.h>

#include "loadso.h"

#if defined(SD_HAVE_DLOPEN)
static int
loadso_symbol_dlopen (void *handle, const char *symbol, void **pointer)
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
#endif

int
loadso_symbol (void *handle, const char *symbol, void **pointer)
{
  assert (handle  != NULL);
  assert (symbol  != NULL);
  assert (pointer != NULL);

#if defined(SD_HAVE_DLOPEN)
  return loadso_symbol_dlopen (handle, symbol, pointer);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
