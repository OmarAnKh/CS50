#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string args[])
{
  string ciphertext = args[1];
  int ciphertextLen = strlen(ciphertext);

  if (strlen(ciphertext) != 26)
  {
    printf("the length of the ciphertext is invalid\n");
    return 0;
  }

  for (int i = 0; i < ciphertextLen; ++i)
  {
    if (!isalpha(ciphertext[i]))
    {
      printf("the ciphertext u entered is invalid\n");
      return 0;
    }

    for (int j = 0; j < i; ++j)
    {
      if (ciphertext[j] == ciphertext[i])
      {
        printf("one of the cipherchar you emtered is doublecated\n");
        return 0;
      }
    }
  }

  string plaintext = get_string("what is the plaintext: ");

  for (int i = 0, n = strlen(plaintext); i < n; ++i)
  {
    if (plaintext[i] >= 65 && plaintext[i] <= 90)
    {

      plaintext[i] = toupper(ciphertext[plaintext[i] - 65]);
    }
    else
    {
      plaintext[i] = tolower(ciphertext[plaintext[i] - 97]);
    }
  }

  printf("%s\n", plaintext);
}