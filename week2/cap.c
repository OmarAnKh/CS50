#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void)
{
    string a = get_string("before: ");

    for (int i = 0, n = strlen(a); i < n; i++)
    {
        if (islower(a[i]))
        {

            printf("%c", toupper(a[i]));
        }

        else if (islower(a[i]) == 0)
        {

            printf("%c", tolower(a[i]));
        }
    }
    printf("\n");
}