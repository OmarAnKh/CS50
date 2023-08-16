#include<stdio.h>
#include<cs50.h>
int main(void)
{
    int points = get_int("how many points did u lose ? ");
   const  int me =2;
 

    if (points < me){
        printf("you lost fewer points than me. \n");
    }

    else if (points > me){
        printf("you lost more points than me. \n ");
    }
    else {
        printf("we lost the same amount of points. \n");
    }
}