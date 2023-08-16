#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_CANDIDATES 9
#define MAX_VOTERS 9

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

candidate candidates[MAX_CANDIDATES];
int preferences[MAX_VOTERS][MAX_CANDIDATES];
int candidateCount;
int numberOfVoter;
int winner;

bool vote(int voter, int rank, string name);
void tabulate(void);
bool printWinner(void);
int findMin(void);
bool isTie(int min);
void elminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("You can not start vote\n");
        return 1;
    }
    candidateCount = argc - 1;
    for (int i = 0; i < candidateCount; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }
    numberOfVoter = get_int("Enter number voter: ");
    for (int i = 0; i < numberOfVoter; i++)
    {
        printf("voter %i \n", i + 1);
        for (int j = 0; j < candidateCount; j++)
        {
            string name = get_string("Enter %i ", j + 1);
            if (!vote(i, j, name))
            {
                printf("The name not found\n");
                return 2;
            }
        }
    }
 while (true)
    {
        tabulate();

        bool won = printWinner();
        if (won)
        {
            break;
        }

        int min = findMin();
        bool tie = isTie(min);

        if (tie)
        {
            for (int i = 0; i < candidateCount; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        elminate(min);

        for (int i = 0; i < candidateCount; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidateCount; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            preferences[voter][rank] = i;
            return true;
        }
    }

    return false;
}

void tabulate(void)
{

    int j = 0;
    for (int i = 0; i < numberOfVoter; i++)
    {
        if (candidates[i].eliminated == false)
        {
            candidates[preferences[i][j]].votes++;
        }
        else
        {
            j++;
        }
    }
}

bool printWinner(void)
{
    for (winner = 0; winner < candidateCount; winner++)
    {
        if (candidates[winner].votes >= ((numberOfVoter / 2) + 1) && candidates[winner].eliminated)
        {
            return true;
        }
    }
    return false;
}

int findMin(void)
{
    int min = numberOfVoter;
    for (int i = 0; i < candidateCount; i++)
    {
        if (candidates[i].eliminated == false && min > candidates[i].votes)
        {
            min = candidates[i].votes;
        }
    }
    return min;
}

bool isTie(int min)
{
    for (int i = 0; i < candidateCount; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes != min)
        {
            return false;
        }
    }
    return true;
}

void elminate(int min)
{
    for (int i = 0; i < candidateCount; i++)
    {
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}