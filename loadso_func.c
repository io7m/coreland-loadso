#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int loadso_func_dlopen(void *h, const char *sym, loadso_fp *func)
{
  loadso_fp f;

#if defined(HAVE_DLFUNC)
  f = (loadso_fp) dlfunc(h, sym);
#else
  f = (loadso_fp) dlsym(h, sym);
#endif
  if (!f) {
    loadso_err = dlerror();
    return 0;
  }
  *func = f;
  return 1;
}
#endif

int loadso_func(void *h, const char *sym, loadso_fp *func)
{
#if defined(HAVE_DLOPEN)
  return loadso_func_dlopen(h, sym, func);
#endif

  loadso_err = "function not implemented on this platform";
  return 0;
}
