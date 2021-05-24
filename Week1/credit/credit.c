#include <stdio.h>
#include <cs50.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int chackdigits(long n)
{
    long newdigit = n;
    long digit = log10(n) + 1;
    return (int)digit;
}

int ctoi(char c)
{
    switch (c)
    {
        case '0':
            return 0;
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        case '9':
            return 9;
        default:
            return 0;
    }
}

int digitcalc(double digit, int num)
{
    char string[30];
    int sumEven[30];
    int sumeven = 0;
    int sumodd = 0;
    int converttonumber[30];
    sprintf(string, "%f", round(digit));
    for (int i = 0; i < num; i++)
    {
        converttonumber[i] = ctoi(string[i]);
        if (num % 2 == 0)
        {
            if (i % 2 == 0)
            {
                int converttonum = ctoi(string[i]);
                int dig;
                int sum = 0;
                int even = (converttonum * 2);
                while (even)
                {
                    dig = even % 10;
                    sum = sum + dig;
                    even = even / 10;
                }
                sumeven += sum;
            }
            else
            {
                int converttonumodd = ctoi(string[i]);
                int dig;
                int sum = 0;
                int odd = converttonumodd;
                while (odd)
                {
                    dig = odd % 10;
                    sum = sum + dig;
                    odd = odd / 10;
                }
                sumodd += sum;
            }
        }
        else
        {
            if (i % 2 != 0)
            {
                int converttonum = ctoi(string[i]);
                int dig;
                int sum = 0;
                int even = (converttonum * 2);
                while (even)
                {
                    dig = even % 10;
                    sum = sum + dig;
                    even = even / 10;
                }
                sumeven += sum;
            }
            else
            {
                int converttonumodd = ctoi(string[i]);
                int dig;
                int sum = 0;
                int odd = converttonumodd;
                while (odd)
                {
                    dig = odd % 10;
                    sum = sum + dig;
                    odd = odd / 10;
                }
                sumodd += sum;
            }
        }
    }

    int istrue = ((sumeven + sumodd) % 10);
    if (istrue == 0)
    {
        int zero = converttonumber[0];
        int one = converttonumber[1];
        if (zero == 5)
        {
            if (one == 1 || one == 2 || one == 3 || one == 4 || one == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (zero == 4 && num >= 13 && num <= 16)
        {
            printf("VISA\n");
        }
        else if (zero == 3 && num >= 15)
        {
            if (one == 4 || one == 7)
            {
                printf("AMEX\n");
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
    else
    {
        printf("INVALID\n");
    }
    return 0;
}

int main(void)
{
    long num = 0;
    do
    {
        num = get_long("Number: ");
    }
    while (num <= 1);
    int getdigit = chackdigits(num);
    digitcalc(num, getdigit);
}