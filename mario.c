#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0, n, j, k = 0;
    do
    {
        n = get_int("Enter a positive integer from 1-8: ");
    } while (n < 1 || n > 8);
    j = n;
    while (i < n)
    {
        i++;
        while (j >= -n)
        {

            if (j > i)
            {
                printf(" ");
            }
            else if (j <= i && j > 0)
            {
                printf("#");
            }
            else if (j == 0)
            {
                printf("  ");
                k++;
            }
            else if (k <= i)
            {
                printf("#");
                k++;
            }
            j--;
        }
        k = 0;
        j = n;
        printf("\n");
    }
}
