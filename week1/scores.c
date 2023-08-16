#include<stdio.h>
#include<cs50.h>
int main(void)
{
int a=get_int("how many scores? ");
    float scores[a];
 for (int i =0 ; i<a;++i){

scores[i]=get_int("what is the score %i ? ",i);
}
     printf("the Average is : %f\n" , (scores[0]+scores[1]+scores[2])/3);
}