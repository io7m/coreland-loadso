#include <stdio.h>
#include "../loadso.h"

int
main (int argc, char *argv[])
{
  loadso_handle_t handle;
  loadso_pointer_t func;
  void *sym;
  void (*test_func)(unsigned int);
  unsigned long test_num;
  const char *test_str;

  if (argc < 2) return 112;

  printf ("info: loading shared object\n");
  if (!loadso_open (argv[1], &handle)) {
    printf ("error: loadso_open: %s\n", loadso_error());
    return 112;
  }

  printf ("info: loading function 'test_func'\n");
  if (!loadso_function (handle, "test_func", &func)) {
    printf ("error: loadso_func: %s\n", loadso_error());
    return 112;
  }
  test_func = (void (*)(unsigned int)) func;

  printf ("info: loading symbol 'test_num'\n");
  if (!loadso_symbol (handle, "test_num", &sym)) {
    printf ("error: loadso_symbol: %s\n", loadso_error());
    return 112;
  }
  test_num = * ((unsigned long *) sym);

  printf ("info: loading symbol 'test_str'\n");
  if (!loadso_symbol (handle, "test_str", &sym)) {
    printf ("error: loadso_symbol: %s\n", loadso_error());
    return 112;
  }
  test_str = * (const char **) sym;

  printf ("info: calling function\n");

  test_func (0);
  test_func (127);
  test_func (255);
  test_func (32767);

  printf ("info: printing symbols\n");
  printf ("info: test_num: %lx\n", test_num);
  printf ("info: test_str: %s\n", test_str);

  printf ("info: closing shared object\n");
  if (!loadso_close (handle)) {
    printf ("error: loadso_close: %s\n", loadso_error());
    return 112;
  }
  return 0;
}
