#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int score(int score[], string input);

int main(int argc, string argv[])
{
    string player1 = get_string("Player1: ");
    string player2 = get_string("Player2: ");
    int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                      1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

    for (int i = 0, num = strlen(player1); i < num; i++)
    {
        player1[i] = toupper(player1[i]);
    }

    for (int i = 0, num = strlen(player2); i < num; i++)
    {
        player2[i] = toupper(player2[i]);
    }

    int score1 = score(points, player1);
    int score2 = score(points, player2);

    if (score1 > score2)
    {
        printf("Player 1 wins! \n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins! \n");
    }
    else
    {
        printf("Tie! \n");
    }
}

int score(int score[], string input)
{
    int sum = 0, ascii, point;
    for (int i = 0, num = strlen(input); i < num; i++)
    {
        ascii = (int)input[i];
        if (ascii < 91 && ascii > 64)
        {
            point = score[ascii - 65];
        }
        else
        {
            point = 0;
        }
        sum += point;
    }
    return sum;
}
