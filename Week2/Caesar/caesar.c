#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{

    char *ascii = argv[1];
    if (atoi(argv[1]) && argc == 2 && isdigit(ascii[0]) && !isalpha(ascii[0]))
    {
        string plainText = get_string("plaintext: ");
        char calc [222];
        int upperbox[111];
        char lowerbox[111];
        char lastNum[111];
        for (int i = 0, n = strlen(plainText); i < n; i++)
        {
            if (isalpha(plainText[i]))
            {
                if (isupper(plainText[i]))
                {
                    upperbox[i] = plainText[i] - 65;
                    calc[i] = (upperbox[i]+atoi(argv[1])) % 26;
                    lastNum[i] = calc[i]+65;
                }
                else if (islower(plainText[i]))
                {
                    lowerbox[i] = plainText[i] - 97;
                    calc[i] = (lowerbox[i] + atoi(argv[1])) % 26;
                    lastNum[i] = calc[i] + 97;
                }
            }
        }
        printf("ciphertext: %s", lastNum);
        printf("\n");
    }
    else if (!atoi(argv[1]) || argc != 2 || !isdigit(ascii[0]))
    {
            printf("Usage: ./caesar key");
    }
}