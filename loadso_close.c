#include <assert.h>
#include <stddef.h>

#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int
loadso_close_dlopen (void *handle)
{
  if (dlclose (handle) != 0) {
    loadso_set_error (dlerror ());
    return 0;
  } else
    return 1;
}
#endif

int
loadso_close (void *handle)
{
  assert (handle != NULL);

#if defined(HAVE_DLOPEN)
  return loadso_close_dlopen (handle);
#endif

  loadso_set_error ("function not implemented on this platform");
  return 0;
}
