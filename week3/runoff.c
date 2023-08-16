#include<cs50.h>

#include<stdio.h>

#include <string.h>

#include<ctype.h>

#include<math.h>

bool vote(int voter, int rank, string name1);

void tabulate(void);

bool print_winner(void);

int find_min(void);

bool is_tie(void);

void eliminate(void);

#define max_candidate 9
#define max_voter 100
int preferences[max_voter][max_candidate];

typedef struct {
   string name;
   int votes;
   bool eliminated;
}
candidate;

candidate candidates[max_candidate];
int number = 0;
int voters_number = 0;
int winner = 0;
int min = 0;
int non_eliminated = 0;

int main(int argc, string name[]) {
   number = argc - 1;

   if (number > max_candidate) {
      printf("the largest number is %i\n", max_candidate);
   }

   for (int i = 0; i < number; i++) {
      candidates[i].name = name[i + 1];
      candidates[i].votes = 0;
      candidates[i].eliminated = false;
   }

   voters_number = get_int("how many voter there is ?\n");

   for (int input = 0; input < voters_number; input++) {

      for (int j = 0; j < number; j++) {

         string voter_input = get_string("Rank %i : ", (j + 1));
         while (!vote(input, j, voter_input)) {
            printf("valid input pleas try again \n");
            voter_input = get_string("Rank %i : ", (j + 1));

         }
      }
      printf("\n \n");
   }

   while (true) {
      tabulate();

      if (print_winner()) {
         printf("%s\n", candidates[winner].name);
         break;
      }

      if (is_tie()) {
         printf("Tie\n");
         break;
      }
      eliminate();

      for (int i = 0; i < number; i++) {
         candidates[i].votes = 0;
      }
   }
   return 0;
}

bool vote(int voter, int rank, string name1) {
   for (int i = 0; i < number; i++) {
      if (!(strcmp(name1, candidates[i].name))) {
         preferences[voter][rank] = i;
         return true;
      }
   }
   return false;
}

void tabulate(void) {
   for (int i = 0; i < voters_number; i++) {
      for (int j = 0; j < number; j++) {
         if (!(candidates[preferences[i][j]].eliminated)) {
            candidates[preferences[i][j]].votes += 1;
            break;
         }

      }
   }
}

bool print_winner(void) {

   for (winner = 0; winner < number; winner++) {
      if (candidates[winner].votes >= ((voters_number / 2) + 1)) {
         return true;
      }
   }
   return false;
}

int find_min(void) {
   int Min = voters_number;

   for (int i = 0; i < number; i++) {

      if (!(candidates[i].eliminated) && candidates[i].votes < Min) {

         Min = candidates[i].votes;
      }
   }
   return Min;
}

bool is_tie() {
   min = find_min();
   for (int i = 0; i < number; i++) {
      if (candidates[i].eliminated == false && candidates[i].votes != min) {
         return false;
      }
   }
   return true;
}

void eliminate(void) {

   min = find_min();
   for (int i = 0; i < number; i++) {

      if (candidates[i].votes == min) {
         candidates[i].eliminated = true;
      }

   }
}