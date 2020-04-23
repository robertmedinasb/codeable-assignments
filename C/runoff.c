#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

int preferences[MAX_VOTERS][MAX_CANDIDATES];

candidate candidates[MAX_CANDIDATES];

int candidates_count;
int voters_count;

bool vote(int i, int j, string name);
bool print_winner(void);
void tabulate(void);
bool is_tie(int min);
int findmin(void);
void eliminate(int min);

int main(int argc, string argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./runoff[candidates]...\n");
        return 1;
    }

    candidates_count = argc;

    if (candidates_count > MAX_CANDIDATES)
    {
        printf("Maximum numbers of candidates is: %i", MAX_CANDIDATES);
        return 2;
    }

    for (int i = 0; i < candidates_count; i++)
    {
        candidates[i].name = argv[i];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voters_count = get_int("Numbers of voters:");

    if (voters_count > MAX_VOTERS)
    {
        printf("Maximum numbers of voters is: %i", MAX_VOTERS);
        return 3;
    }

    for (int i = 0; i < voters_count - 1; i++)
    {
        for (int j = 0; j < candidates_count; j++)
        {
            string name = get_string("Rank %i:", j + 1);

            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }
        printf("\n");
    }

    while (true)
    {
        tabulate();

        bool won = print_winner();

        if (won)
        {
            break;
        }

        int min = findmin();
        bool tie = is_tie(min);
        if (tie)
        {
            for (int i = 0; i < candidates_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        eliminate(min);

        for (int i = 0; i < candidates_count; i++)
        {
            candidates[i].votes = 0;
        }

        return 0;
    }
}

bool vote(int x, int y, string name)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            preferences[x][y] = i;
            return true;
        }
    }
    return false;
}

void tabulate(void)
{
    for (int i = 0; i < voters_count; i++)
    {
        for (int j = 0; j < candidates_count; j++)
        {
            if (candidates[j].eliminated == false)
            {
                candidates[preferences[i][j]].votes++;
                break;
            }
        }
    }
    return;
}

bool print_winner(void)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes > (voters_count * 0.5))
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

int findmin(void)
{
    int min[1] = {0};
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes > min[0])
        {
            min[0] = candidates[i].votes;
        }
    }
    return min[0];
}

bool is_tie(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes != min && candidates[i].eliminated == false)
        {
            return false;
        }
    }
    return true;
}

void eliminate(int min)
{
    for (int i = 0; i < candidates_count; i++)
    {
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}