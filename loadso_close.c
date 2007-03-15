#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int loadso_close_dlopen(void *h)
{
  if (dlclose(h) != 0) {
    loadso_err = dlerror();
    return 0;
  } else
    return 1;
}
#endif

int loadso_close(void *h)
{
#if defined(HAVE_DLOPEN)
  return loadso_close_dlopen(h);
#endif

  loadso_err = "function not implemented on this platform";
  return 0;
}
