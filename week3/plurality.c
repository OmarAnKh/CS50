#include<cs50.h>

#include<stdio.h>

#include <string.h>

void print_winner(void);
bool vote1(string a);
#define max 9
typedef struct {

   string name;
   int vote;

}
candidate;
candidate number1[max];

int d = 0;
int main(int argc, string name[]) {

   d = argc - 1;
   if (d > max) {
      printf("the largest number is %i \n", max);
      return 1;
   }
   for (int i = 0; i <= d; ++i) {
      number1[i].name = name[i + 1];
      number1[i].vote = 0;
   }

   int many = get_int("how many one wants to vote? \n");
   for (int i = 0; i < many; ++i) {
      string who = get_string("who do u want to vote for? \n ");
      if (!vote1(who)) {
         printf("this name is not available");

      }
   }
   print_winner();

}

bool vote1(string a) {
   for (int i = 0; i < d; ++i) {
      if (strcmp(a, number1[i].name) == 0) {
         ++number1[i].vote;
         return 1;
      }

   }
   return 0;
}

void print_winner(void) {
   int max1 = 0;
   for (int i = 0; i < d; ++i) {
      if (number1[i].vote > max1) {
         max1 = number1[i].vote;
      }
   }
   for (int i = 0; i < d; ++i) {
      if (number1[i].vote == max1) {
         printf("the winner is %s \n", number1[i].name);
      }
   }
}