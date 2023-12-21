#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    int i = 0;
    while (i < candidate_count)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
        else
        {
            i++;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int s;
    do
    {
        int i = 0;
        int j = 1;
        s = 0;

        do
        {
            if (candidates[i].votes < candidates[j].votes)
            {
                string a;
                string b;
                int c;
                int d;
                a = candidates[i].name;
                b = candidates[j].name;
                c = candidates[i].votes;
                d = candidates[j].votes;
                candidates[j].name = a;
                candidates[i].name = b;
                candidates[i].votes = d;
                candidates[j].votes = c;

                s++;
            }
            i++;
            j = i + 1;
        }
        while (j < candidate_count);
    }
    while (s > 0);

    int m = 1;
    do
    {
        if (candidates[0].votes == candidates[m].votes)
        {
            m++;
        }

        else
        {
            for (int n = 0; n < m; n++)
            {
                printf("%s\n", candidates[n].name);
            }
            return;
        }
    }
    while (m < candidate_count);

    for (int n = 0; n < m; n++)
            {
                printf("%s\n", candidates[n].name);
            }




}