#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int loadso_open_dlopen(const char *file, void **hand)
{
  void *h;
  h = dlopen(file, RTLD_NOW);
  if (!h) {
    loadso_err = dlerror();
    return 0;
  }
  *hand = h;
  return 1;
}
#endif

int loadso_open(const char *file, void **hand)
{
#if defined(HAVE_DLOPEN)
  return loadso_open_dlopen(file, hand);
#endif

  loadso_err = "function not implemented on this platform";
  return 0;
}
