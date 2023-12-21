#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Ask user for the height

    int x;
    do
    {
        x = get_int("Height: ");
    }
    while (x < 1 || x > 8);

    //print the bricks

    int n = 1;
    for (int i = 0 ; i < x ; i++)
    {
        //printing the first half

        for (int j = 0; j < x - n ; j++)
        {
            printf(" ");
        }
        for (int k = 0; k < n ; k++)
        {
            printf("#");
        }

        //printing the middle gap

        printf("  ");

        //printing the second half

        for (int l = 0; l < n ; l++)
        {
            printf("#");
        }
        
        printf("\n");
        n++ ;
    }

}