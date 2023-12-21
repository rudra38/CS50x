#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    float pi;
    do
    {
        pi = get_int("Start Size: ");
    }
    while (pi < 9);

    // TODO: Prompt for end size

    float pf;
    do
    {
        pf = get_int("End size: ");
    }
    while (pf < pi);

    // TODO: Calculate number of years until we reach threshold

    int y = 0;

    if (pi != pf)
    {
        do
        {
            y++;
            pi = pi + pi / 3 - pi / 4;
        }
        while (pf > pi + pi / 3 - pi / 4);

        y++;
        pi = pi + pi / 3 - pi / 4;

        // TODO: Print number of years

        if (pi == pf)
        {
            printf("Years: %i", y);
        }

        else if (pf < pi)
        {
            printf("Years: %i", y - 1);
        }
    }

    else
    {
        printf("Years: 0");
    }

}
