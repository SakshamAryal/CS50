#include <stdio.h>

const int N = 3;
float average(int length, int array[]);

int main(void)
{
    int score[N];
    for (int i = 0; i < N; i++)
    {
        printf("Get score: ");
        scanf("%d", &score[i]);
    }

    printf("The average score is %f", average(N, score));
}

float average(int length, int array[])
{
    int sum = 0;

    for (int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float)length;
}