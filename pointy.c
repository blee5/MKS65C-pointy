#include <stdio.h>

int main()
{
  unsigned int n = 268435456;
  char *p = &n;
  int num_loops = sizeof(int) / sizeof(char);
  int counter;

  printf("Original: %u, %X\n", n, n);

  printf("Reading individual bytes\n==============\n");
  for (counter = 0; counter < num_loops; counter++)
  {
    printf("%hhu\n", *p);
    p++;
  }
  printf("==============\n");

  p = &n;
  for (counter = 0; counter < num_loops; counter++)
  {
    (*p)++;
    p++;
  }
  printf("After adding 1 to each byte: %u, %X\n", n, n);

  p = &n;
  for (counter = 0; counter < num_loops; counter++)
  {
    *p += 16;
    p++;
  }
  printf("After adding 16 to each byte: %u, %X\n", n, n);

  p = &n;
  for (counter = 0; counter < num_loops; counter++)
  {
    *p = 0xDE;
    p++;
  }
  printf("After setting each byte to DE : %u, %X\n", n, n);

  return 0;
}
