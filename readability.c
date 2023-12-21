#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);


int main(void)
{
    //  Ask the user for text input
    string a = get_string("Text: ");

    //Count the no. of letters
    int letters = count_letters(a);

    //Count the no. of words
    int words = count_words(a);

    //Count the no. of sentences
    int sentences = count_sentences(a);

    //Put in formula
    float l = ((float)letters / words) * 100;
    float s = ((float)sentences / words) * 100;

    int grade = round((0.0588 * l) - (0.296 * s) - 15.8);

    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", grade);
    }

}


//function for letters


int count_letters(string text)
{
    int l = 0;
    int t = 0;
    int len = strlen(text);

    do
    {
        if (isupper(text[t]) || islower(text[t]))
        {
            t++;
            l++;
        }

        else
        {
            t++;
        }
    }
    while (t <= len);

    return l;
}


//function for words


int count_words(string text)
{
    int c = 0;
    int w = 0;
    int k = 0;
    int len = strlen(text);

    do
    {
        if (text[c] == ' ' && k == 0)
        {
            c++;
        }

        else if (text[c] == ' ' && k > 0)
        {
            c++;
            w++;
            k = 0;
        }

        else if (text[c] != ' ')
        {
            c++;
            k++;
        }
    }
    while (c <= len);

    w++;
    return w;

}


//funtion for sentences

int count_sentences(string text)
{
    int c = 0;
    int s = 0;
    int len = strlen(text);


    do
    {
        if (text[c] == '.' || text[c] == '!' || text[c] == '?')
        {
            s++;
            c++;
        }

        else
        {
            c++;
        }
    }
    while (c <= len);

    return s;

}