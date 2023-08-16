#include <stdio.h>
#include <cs50.h>
string valid_triangle(double a, double b, double c)
{
    if (a <= 0 || b <= 0 || c <= 0)
    {
        return "false";
    }
    else if (a + b <= c || a + c <= b || c + b <= a)
    {
        return "false";
    }
    else
    {
        return "true";
    }
}
int main(void)
{
    double a = get_double("what is the a side length? ");
    double b = get_double("what is the b side length? ");
    double c = get_double("what is the c side length? ");
    string x = valid_triangle(a, b, c);
    printf("%s \n", x);
}