#include <stdio.h>

unsigned long test_num = 0xf0f0f0f0;
const char *test_str = "loadso test string";

void test_func(unsigned int x)
{
  printf("test_func: %u\n", x);
}
