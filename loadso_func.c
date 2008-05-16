#include "_sd-ptr_uint.h"
#include "loadso.h"

#if defined(HAVE_DLOPEN)
static int loadso_func_dlopen(void *h, const char *sym, loadso_fp *func)
{
  loadso_fp f;
  ptr_uint p;

/* subvert C99 object/function pointer <-> type rules... unfortunately */
#if defined(HAVE_DLFUNC)
  f = (loadso_fp) dlfunc(h, sym);
  p = 0;
#else
  p = (ptr_uint) dlsym (h, sym);
  f = (loadso_fp) p;
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
