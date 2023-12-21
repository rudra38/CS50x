#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int repeated(string text);
int na(string text);

int main(int argc, string argv[])
{
    while (argc != 2)
    {
        printf("error");
        return 1;
    }

    int len = strlen(argv[1]);

    while (len != 26)
    {
        printf("error");
        return 1;
    }


    while (repeated(argv[1]) == 0)
    {
        printf("error");
        return 1;
    }


    while (na(argv[1]) == 0)
    {
        printf("error");
        return 1;
    }




    if (len == 26 && na(argv[1]) == 1 && repeated(argv[1]) == 1)
    {
        int i = 0;
        int c = 0;

        string s = get_string("plaintext: ");
        int len2 = strlen(s);

        char ct[len2];

        while (c <= len2)
        {
            if (isupper(s[c]))
            {
                i = s[c] - 'A';
                ct[c] = toupper(argv[1][i]);
                i = 0;
                c++;
            }

            else if (islower(s[c]))
            {
                i = s[c] - 'a';
                ct[c] = tolower(argv[1][i]);
                i = 0;
                c++;
            }

            else
            {
                ct[c] = s[c];
                c++;
            }
        }

        printf("ciphertext: %s\n", ct);
    }

}


int repeated(string text)
{
    int i = 0;


    do
    {
        int j = i + 1;
        while (j <= 25)
        {
            if (tolower(text[i]) == tolower(text[j]))
            {
                return 0;
            }

            else
            {
                j++;
            }
        }

        i++;
    }
    while (i < 25);

    return 1;

}

int na(string text)
{
    int c = 0;
    while (c < 26)
    {
        if (isupper(text[c]) || islower(text[c]))
        {
            c++;
        }

        else
        {
            return 0;
        }
    }

    return 1;
}