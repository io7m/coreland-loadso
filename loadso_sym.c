#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int loadso_sym_dlopen(void *h, const char *sym, void **ptr)
{
  void *p;
  p = dlsym(h, sym);
  if (!p) {
    loadso_err = dlerror();
    return 0;
  }
  *ptr = p;
  return 1;
}
#endif

int loadso_sym(void *h, const char *sym, void **ptr)
{
#if defined(HAVE_DLOPEN)
  return loadso_sym_dlopen(h, sym, ptr);
#endif

  loadso_err = "function not implemented on this platform";
  return 0;
}
