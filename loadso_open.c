#include <stddef.h>
#include <assert.h>

#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int
loadso_open_dlopen (const char *file, void **handle)
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
#endif

int
loadso_open (const char *file, void **handle)
{
  assert (file   != NULL);
  assert (handle != NULL);

#if defined(HAVE_DLOPEN)
  return loadso_open_dlopen (file, handle);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
