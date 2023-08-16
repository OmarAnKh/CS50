#include <stdio.h>
#include <cs50.h>
void meow(int n);
int main(void)
{
  int a = get_int("how many times do u want it to meow ");
  meow(a);
}

void meow(int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("meow\n");
  }
}