#include "ctxt.h"
#include "install.h"

struct install_item insthier[] = {
  {INST_MKDIR, 0, 0, ctxt_bindir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_incdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_dlibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_slibdir, 0, 0, 0755},
  {INST_MKDIR, 0, 0, ctxt_repos, 0, 0, 0755},
  {INST_COPY, "loadso-conf.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso_close.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso_error.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso_func.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso_open.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso_sym.c", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_sd_ptr_uint.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "_sd_ptr_uint.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "loadso.h", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso.h", 0, ctxt_incdir, 0, 0, 0644},
  {INST_COPY, "loadso.sld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY, "loadso.a", "libloadso.a", ctxt_slibdir, 0, 0, 0644},
  {INST_COPY, "loadso-conf.ld", 0, ctxt_repos, 0, 0, 0644},
  {INST_COPY_EXEC, "loadso-conf", 0, ctxt_bindir, 0, 0, 0755},
};
unsigned long insthier_len = sizeof(insthier) / sizeof(struct install_item);
