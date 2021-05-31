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
// codegym
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int doencrypt(string text, int num);
int main(int argc, string argv[])
{

    if (argc == 2)
    {
        int num = atoi(argv[1]);
        string text = get_string("plaintext:  ");
        doencrypt(text, num);
    }
    else if (argc != 2)
    {
        printf("Usage: ./caesar key");
        return 1;
    }
}

int doencrypt(string text, int num)
{
    char encrypttext[strlen(text)];
    for (int i = 0 ; strlen(text) > i; i++)
    {
        int changedtext = text[i] + num;
        encrypttext[i] = changedtext;
        if (isalpha(text[i]))
        {
            if (changedtext <= 122 && changedtext >= 97)
            {
                encrypttext[i] = changedtext;
            }
            else if (changedtext <= 90 && changedtext >= 65)
            {
                encrypttext[i] = changedtext;
            }
            else
            {
                if (isupper(text[i]))
                {
                    encrypttext[i] = (text[i] - 65 + num) % 26 + 65;
                }
                else if (islower(text[i]))
                {
                    encrypttext[i] = (text[i] - 97 + num) % 26 + 97;
                }
            }

        }
        else
        {
            encrypttext[i] = text[i];
        }
    }
    printf("ciphertext: %s\n", encrypttext);
    return 0;
}