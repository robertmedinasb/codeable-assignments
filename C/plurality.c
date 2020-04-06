#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define MAX 9

typedef struct
{
    string names;
    int votes;
}
candidate;

candidate candidates[MAX];

 int candidate_count;

bool vote(string name);
void print_winner(void);
int main(int argc, string argv[])

{
    if(argc<2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 0;
    }

    candidate_count = argc-1;

    if (candidate_count > MAX)
    {
       printf("Maximun number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i =0; i<candidate_count;i++)
    {
        candidates[i].names = argv[i+1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Numbers of voters: ");

    for (int i = 0; i<voter_count; i++)
    {
       string name = get_string("Vote: ");

        if (!vote(name))
        {
           printf("Invalid vote. \n");
        }
    }

    print_winner();
}

bool vote(string name)
{
    for (int i = 0; i<candidate_count; i++)
    {
        if (strcmp(candidates[i].names, name)==0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    int maxvotes = 0;
    for (int i = 0; i < candidate_count; i++ )
    {
        if (candidates[i].votes > maxvotes)
        {
            maxvotes = candidates [i].votes;
        }
    }

    for (int i = 0 ; i < candidate_count; i++)
    {
        if (candidates[i].votes == maxvotes)
        {
            printf("%s\n", candidates[i].names);
        }
    }

    return;
}