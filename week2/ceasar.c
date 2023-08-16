#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int main(int number, string args[])
{
  string text = get_string("what is the plaintext? ");
  int cipher = atoi(args[1]);

  for (int i = 0, n = strlen(text); i < n; ++i)
  {
    char loweredChar = tolower(text[i]);

    if (loweredChar >= 'a' && loweredChar <= 'z')
    {
      text[i] += cipher;

      if (tolower(text[i]) >= 'z')
      {
        text[i] = 'a' + cipher % 26;
      }
    }
  }

  printf("the encipher code is %s \n", text);
}
