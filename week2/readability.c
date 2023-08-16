#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
int main(void)
{
    string text = get_string("what is the sentence?  ");

    int char1 = 0;
    int word = 0;
    int sentence = 0;
    for (int i = 0, n = strlen(text); i < n; ++i)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            char1++;
        }
        else if (text[i] == ' ')
        {
            ++word;
        }
        else if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            ++sentence;
        }
    }
    float sum = (0.0588 * char1 / word * 100 - 0.296 * sentence / word * 10 - 15.8);

    int c = round(sum);

    printf("grade %i\n", c);
}