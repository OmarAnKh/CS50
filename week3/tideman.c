#include <cs50.h>

#include <stdio.h>

#include <string.h>

#include <ctype.h>

#include <math.h>

void record_preferences(int ranks[]);
bool vote(int rank, string name, int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
bool to_check(void);
void print_winner(void);

#define max_candidate 9
#define max_voter 100

typedef struct
{
   int losser;
   int winner;
} pairs;

pairs pair[max_candidate];

int pair2[max_candidate];
string candidates[max_candidate];
int preferences[max_candidate][max_candidate];
bool locked[max_candidate][max_candidate];
int candidate_number = 0;
int voters_number = 0;
int pairs_count = 0;
int arows_counter = 0;

int main(int argc, string name[])
{
   candidate_number = argc - 1;
   int ranks[max_candidate];

   if (candidate_number > max_candidate)
   {
      printf("the largest number is %i\n", max_candidate);
   }

   for (int i = 0; i < candidate_number; i++)
   {
      candidates[i] = name[i + 1];
   }

   voters_number = get_int("how many voter there is ?\n");

   for (int input = 0; input < voters_number; input++)
   {

      for (int j = 0; j < candidate_number; j++)
      {

         string voter_input = get_string("Rank %i : ", (j + 1));
         while (!vote(j, voter_input, ranks))
         {
            printf("valid input pleas try again \n");
            voter_input = get_string("Rank %i : ", (j + 1));
         }
      }

      record_preferences(ranks);

      printf("\n \n");
   }
   add_pairs();
   sort_pairs();
   lock_pairs();
   print_winner();
}

bool vote(int rank, string name, int ranks[])
{
   for (int i = 0; i < candidate_number; ++i)
   {
      if (!strcmp(name, candidates[i]))
      {
         ranks[rank] = i;
         return true;
      }
   }
   return false;
}

void record_preferences(int ranks[])
{
   for (int i = 0; i < voters_number; i++)
   {
      for (int j = i + 1; j < candidate_number; j++)
      {
         preferences[ranks[i]][ranks[j]]++;
      }
   }
}

void add_pairs(void)
{
   for (int i = 0, counter = 0; i < candidate_number; i++)
   {
      for (int j = i; j < candidate_number; j++)
      {
         if (i == j)
         {
            continue;
         }
         if (preferences[i][j] > preferences[j][i])
         {
            pair[counter].winner = i;
            pair2[counter] = i;
         }
         else if (preferences[j][i] > preferences[i][j])
         {
            pair[counter].winner = j;
            pair2[counter] = j;
         }

         if (preferences[i][j] < preferences[j][i])
         {
            pair[counter].losser = i;
         }
         else if (preferences[j][i] < preferences[i][j])
         {
            pair[counter].losser = j;
         }
         counter++;
      }
   }
}

void sort_pairs(void)
{
   for (int i = 0; i < candidate_number; i++)
   {
      for (int j = 0; j < candidate_number; j++)
      {
         if ((preferences[pair[i].winner][pair[i].losser] - preferences[pair[i].losser][pair[i].winner]) < (preferences[pair[j].winner][pair[j].losser] - preferences[pair[j].losser][pair[j].winner]))
         {
            int temp = pair2[i];
            pair2[i] = pair2[j];
            pair2[j] = temp;
         }
      }
   }
}

void lock_pairs(void)
{
   for (int i = 0; i < candidate_number; i++)
   {
      locked[pair[i].winner][pair[i].losser] = true;
   }

   if (!(to_check()))
   {
      for (int i = 0; i < candidate_number; i++)
      {
         for (int j = 0; j < candidate_number; j++)
         {
            locked[i][j] = false;
         }
      }

      for (int i = 0; i < candidate_number - 1; i++)
      {
         locked[pair2[i]][pair[i].losser] = true;
      }
   }
}

bool to_check(void)
{
   for (int i = 0; i < candidate_number; i++)
   {
      for (int j = 0; j < candidate_number; j++)
      {
         if (locked[j][i] == true)
         {
            arows_counter++;
            break;
         }
      }
   }
   if (arows_counter == candidate_number)
   {
      return false;
   }

   return true;
}

void print_winner(void)
{
   int counter = 0;
   int i;
   for (i = 0; i < candidate_number; i++)
   {
      counter = 0;
      for (int j = 0; j < candidate_number; j++)
      {
         if (locked[j][i] == true)
         {
            counter = 1;
            break;
         }
      }
      if (!counter)
      {
         printf("%s \n", candidates[i]);
         break;
      }
   }
}