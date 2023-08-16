#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int getSentenceScore(string sentence)
{
  int score = 0;

  for (int i = 0, n = strlen(sentence); i < n; ++i)
  {
    if (tolower(sentence[i]) == 'a')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'b')
    {
      score += 3;
    }
    else if (tolower(sentence[i]) == 'c')
    {
      score += 3;
    }
    else if (tolower(sentence[i]) == 'd')
    {
      score += 2;
    }
    else if (tolower(sentence[i]) == 'e')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'f')
    {
      score += 4;
    }
    else if (tolower(sentence[i]) == 'g')
    {
      score += 2;
    }
    else if (tolower(sentence[i]) == 'h')
    {
      score += 4;
    }
    else if (tolower(sentence[i]) == 'i')
    {
      score += 2;
    }
    else if (tolower(sentence[i]) == 'j')
    {
      score += 8;
    }
    else if (tolower(sentence[i]) == 'k')
    {
      score += 5;
    }
    else if (tolower(sentence[i]) == 'l')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'm')
    {
      score += 3;
    }
    else if (tolower(sentence[i]) == 'n')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'o')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'p')
    {
      score += 3;
    }
    else if (tolower(sentence[i]) == 'q')
    {
      score += 10;
    }
    else if (tolower(sentence[i]) == 'r')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 's')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 't')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'u')
    {
      score += 1;
    }
    else if (tolower(sentence[i]) == 'w')
    {
      score += 4;
    }
    else if (tolower(sentence[i]) == 'v')
    {
      score += 4;
    }
    else if (tolower(sentence[i]) == 'x')
    {
      score += 8;
    }
    else if (tolower(sentence[i]) == 'y')
    {
      score += 4;
    }
    else if (tolower(sentence[i]) == 'z')
    {
      score += 10;
    }
    else
    {
      score += 0;
    }
  }

  return score;
}

int main(void)
{
  string firstSentence = get_string("player 1: ");
  int firstSentenceScore = getSentenceScore(firstSentence);
  string secondSentence = get_string("player 2: ");
  int secondSentenceScore = getSentenceScore(secondSentence);

  if (firstSentenceScore > secondSentenceScore)
  {
    printf("player 1 won 🎉✨(づ￣ 3￣)づ \n");
  }
  else if (secondSentenceScore > firstSentenceScore)
  {
    printf("player 2 won 🎉✨(づ￣ 3￣)づ \n");
  }
  else if (secondSentenceScore == firstSentenceScore)
  {
    printf("draw (￣o￣) . z Z  \n");
  }
}