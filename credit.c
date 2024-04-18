#include <stdio.h>
#include <stdbool.h>

bool is_mastercard(long long mas, bool luhn);

bool is_visa(long long vi, bool luhn);

bool is_american(long long ame, bool luhn);

bool is_visa13(long long vi, bool luhn);

int main(void)
{

    int comparision;
    long long card;
    do
    {
        printf("Number: ");
        scanf("%lld", &card);
    } while (card < 999999999);

    if (card < 999999999999)
    {
        printf("INVALID\n");
        return 0;
    }

    long long card2 = card, k = 10, rem = 0, total1 = 0, total2 = 0, final, check = 10;
    int card_num = 0;
    bool luhn;

    if (card < 9999999999999 && card > 999999999999)
    {
        card_num = 13;
    }
    else if (card < 999999999999999 && card > 9999999999999)
    {
        card_num = 15;
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
        luhn = true;
    }
    else
    {
        luhn = false;
    }

    bool mastercard = is_mastercard(card2, luhn);
    bool visa = is_visa(card2, luhn);
    bool amex = is_american(card2, luhn);
    bool visa2 = is_visa13(card2, luhn);

    if (mastercard == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true || visa2 == true)
    {
        printf("VISA\n");
    }
    else if (amex == true)
    {
        printf("AMEX\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool is_mastercard(long long mas, bool luhn)
{
    bool is_mas;
    if (mas > 999999999999999)
    {
        mas = mas / 100000000000000;
    }
    if (mas > 50 && mas < 56 && luhn == true)
    {
        is_mas = true;
    }
    else
    {
        is_mas = false;
    }
    return is_mas;
}

bool is_visa13(long long vi, bool luhn)
{
    bool is_vis13;
    if (vi > 999999999999 && vi < 99999999999999)
    {
        vi = vi / 1000000000000;
    }
    if (vi == 4 && luhn == true)
    {
        is_vis13 = true;
    }
    else
    {
        is_vis13 = false;
    }
    return is_vis13;
}

bool is_visa(long long vis, bool luhn)
{
    bool is_vis16;
    if (vis > 999999999999999)
    {
        vis = vis / 1000000000000000;
    }
    if (vis == 4 && luhn == true)
    {
        is_vis16 = true;
    }
    else
    {
        is_vis16 = false;
    }
    return is_vis16;
}

bool is_american(long long ame, bool luhn)
{
    bool is_ame;
    if (ame > 99999999999999)
    {
        ame = ame / 10000000000000;
    }
    if (ame == 32 || ame == 37)
    {
        if (luhn == true)
        {
            is_ame = true;
        }
        else
        {
            is_ame = false;
        }
    }
    else
    {
        is_ame = false;
    }

    return is_ame;
}
