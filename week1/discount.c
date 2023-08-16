#include<stdio.h>
#include<cs50.h>

float discount(float a, int j){
    return a * (100 - j) / 100;
}

int main(void) {
    float b = get_float("what is the price befor the discount? ");
    int d = get_int("what is the percent of discount? ");
    float c = discount(b,d);

    printf("the price after the discount  is %.2f \n" ,c );
}
