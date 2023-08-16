#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int main(int agrc, string tex[])
{
  string text1 = get_string("Enter text: ");
  int x = atoi(tex[1]);
  for (int i = 0; i < strlen(text1); i++)
  {
    if (isalpha(text1[i]))
    {
      if (text1[i] > 90 || text1[i] > 122)
      {
        if (isupper(text1[i]))
        {
          text1[i] = text1[i] + x;
        }
        else if (islower(text1[i]))
        {
          text1[i] = text1[i] + x;
        }
      }
    }
  }

  printf("The new: %s \n", text1);
}