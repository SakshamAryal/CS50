#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

    if (argc != 2)
    {
        fprintf(stderr, "%s <key> \n", argv[0]);
        return 1;
    }
    if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else if (strlen(argv[1]) == 26)
    {

        for (int i = 0; i < 26; i++)
        {
            if (isalpha(argv[1][i]) == false)
            {
                return 1;
            }
        }
        int n = 0;
        for (int i = 0; i < 26; i++)
        {
            n = 0;
            for (int j = 0; j < 26; j++)
            {
                if ((65 + i) == toupper(argv[1][j]))
                {
                    n = n + 1;
                }
            }
            if (n > 1)
            {
                return 1;
            }
        }
    }

    char *key = argv[1];
    string word = get_string("plaintext: ");
    char alph[26];

    int ascii;
    string encrypted = word;

    for (int i = 0, num = strlen(word); i < num; i++)
    {
        if (isalpha(word[i]))
        {
            if (isupper(word[i]))
            {
                ascii = (int)word[i];
                encrypted[i] = toupper(key[ascii - 65]);
            }
            else if (islower(word[i]))
            {
                ascii = (int)word[i];
                encrypted[i] = tolower(key[ascii - 97]);
            }
        }
        else if (isspace(word[i]))
        {
            encrypted[i] = (32);
        }
    }

    printf("ciphertext: %s\n", encrypted);
}
