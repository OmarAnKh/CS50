#include<stdio.h>
#include<cs50.h>
int main(void)
{
double   x = get_double("x: ");
double y = get_double("y: ");
double z = x/y;
printf("the sum is %.50f\n" ,z);
}