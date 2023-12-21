#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    //Prompt user for card no.
    long c;
    do
    {
        c = get_long("Number: ");
    }
    while (c < 0);

    //Specialise variables to be used later
    
    long b = c;
    long a = c;
    long m = c;
    int y = 0;
    int o = m / pow(10, 15);
    int x = m / pow(10, 13);
    int p = m / pow(10, 12);
    int d = m / pow(10, 14);

    //Check Luhn's Algorithm on it
    //Calculating n1

    int n1 = 0;
    do
    {
        int k = 2 * ((c % 100) / 10);
        k = k / 10 + k % 10;
        c = c / 100;
        n1 = n1 + k;
    }
    while (c > 0);

    //calculating n2

    int n2 = 0;
    do
    {
        int l = (b % 10);
        l = l / 10 + l % 10;
        b = b / 100;
        n2 = n2 + l;
    }
    while (b > 0);

    if ((n1 + n2) % 10 == 0)
    {
        // Check the no. of digits

        do
        {
            a = a / 10;
            y++;
        }
        while (a > 0);

        //print

        if (y == 15 && (x == 34 || x == 37))
        {
            printf("AMEX\n");
        }

        else if (y == 16 && (d == 51 || d == 52 || d == 53 || d == 54 || d == 55))
        {
            printf("MASTERCARD\n");
        }

        else if ((y == 13 || y == 16) && (p == 4 || o == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    // print invalid if luhn's algorithm doesn't match
    else
    {
        printf("INVALID\n");
    }





}