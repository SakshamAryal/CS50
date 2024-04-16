#include <stdio.h>

int main(void)
{
    int i = 0, n, j, k = 0;
    do
    {
        printf("Enter a positive integer from 1-8: ");
        scanf("%d", &n);
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
