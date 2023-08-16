#include <cs50.h>
#include <stdio.h>
int main(void)
{
    int a = get_int("how many blocks do u want? ");
    for (int i = 0; i <= a; ++i)
    {

        for (int j = 0; j <= a; ++j)
        {
            printf("#");
        }
        printf("\n");
    }
}