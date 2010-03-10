#include <assert.h>
#include <stddef.h>

#include "loadso.h"

static const char *loadso_err = "no error";

const char *
loadso_error (void)
{
  assert (loadso_err != NULL);
  return loadso_err;
}

void
loadso_set_error (const char *e)
{
  assert (e != NULL);
  loadso_err = e;
}
