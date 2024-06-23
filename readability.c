#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// need two variables: L and S
// l is the no. of letters per 100 words and s is the no. of sentences per 100 words

int letters(string input);
int words(string input);
int sentences(string input);

int main(int argc, string argv[])
{
    string text = get_string("Text: ");
    float L, S, index;

    for (int i = 0, num = strlen(text); i < num; i++)
    {
        text[i] = toupper(text[i]);
    }

    int letterc = letters(text);
    int wordc = words(text);
    int sentencec = sentences(text);

    L = (float)letterc / (wordc) * 100;
    S = (float)sentencec / (wordc) * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        for (int i = 2; i < 16; i++)
        {
            if (index >= i - 0.5 && index < i + 0.5)
            {
                printf("Grade %i\n", i);
            }
        }
    }
}

int letters(string input)
{
    int letters = 0;
    for (int i = 0, num = strlen(input); i < num; i++)
    {

        if (isupper(input[i]))
        {
            letters += 1;
        }
    }
    return letters;
}

int words(string input)
{
    int words = 1;
    for (int i = 0, num = strlen(input); i < num; i++)
    {
        if (isspace(input[i]))
        {
            words += 1;
        }
    }
    return words;
}

int sentences(string input)
{
    int sentences = 0;
    for (int i = 0, num = strlen(input); i < num; i++)
    {
        if (input[i] == 33 || input[i] == 46 || input[i] == 63)
        {
            sentences += 1;
        }
    }
    return sentences;
}
