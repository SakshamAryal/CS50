#include <stdio.h>

int is_mastercard(long mas);

int is_visa(long vi);

int is_american(long ame);

int is_visa13(long vi);

int main(void)
{
    int comparision;
    long long card;
    long long check2 = 9999999999;
    do
    {
        printf("Number: ");
        scanf("%lld", &card);
        printf("%lld", card);
    } while (card < check2);

    long k = 10;
    long rem = 0, total1 = 0, total2 = 0, final, check = 10;
    long mastercard = is_mastercard(card);
    long visa = is_visa(card);
    long amex = is_american(card);
    long visa2 = is_visa13(card);
    int card_num = 0;

    if (card < 9999999999999 && card > 999999999999)
    {
        card_num = 13;
    }
    else if (card < 999999999999999 && card > 9999999999999)
    {
        card_num = 15;
    }
    else if (card < 999999999999)
    {
        printf("INVALID\n");
    }
    else
    {
        card_num = 16;
    }

    for (int i = 0; i < card_num; i++)
    {
        rem = card % k;
        card = card / 10;

        if (i % 2 != 0)
        {
            rem = rem * 2;

            if (rem > 9)
            {
                rem = rem % 10 + 1;
            }
            total1 = total1 + rem;
        }
        else
        {
            total2 = total2 + rem;
        }
    }

    final = total1 + total2;

    if (final % check == 0)
    {
        if (mastercard < 56 && mastercard > 50)
        {
            printf("MASTERCARD\n");
        }
        else if (amex == 34 || amex == 37)
        {
            printf("AMEX\n");
        }
        else if (visa == 4)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}

int is_mastercard(long mas)
{
    if (mas > 999999999999999)
        mas = mas / 100000000000000;
    return mas;
}

int is_visa13(long vi)
{
    if (vi > 999999999999 && vi < 99999999999999)
    {
        vi = vi / 100000000000;
    }
    return vi;
}

int is_visa(long vis)
{
    if (vis > 999999999999999)
    {
        vis = vis / 100000000000000;
    }
    return vis;
}

int is_american(long ame)
{
    if (ame > 99999999999999)
    {
        ame = ame / 100000000000000;
    }

    return ame;
}
