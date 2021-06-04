#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int doencrypt(string text, string plaintext);


int main(int argc, string argv[])
{
    if (argc == 2 && strlen(argv[1]) < 26)
    {
        printf("Key must contain 26 characters.");
        return 1;
    }
    else if (argc != 2)
    {
        printf("Usage: ./substitution key");
        return 1;
    }
    else
    {
        for (int i = 0; strlen(argv[1]) > i; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Usage: ./substitution key");
                return 1;
            }
            for (int j = 0; strlen(argv[1]) > j; j++)
            {
                if (argv[1][0] == argv[1][j + 1])
                {
                    printf("Usage: ./substitution key");
                    return 1;
                }
                else if (argv[1][i] == argv[1][i + 1])
                {
                    printf("Usage: ./substitution key");
                    return 1;
                }
            }
        }
        string getplaintext = get_string("plaintext:  ");
        doencrypt(argv[1], getplaintext);
    }
    return 0;
}

char upper(char c)
{
    if ('a' <= c && c <= 'z')
    {
        c = c - ('a' - 'A');
    }
    return c;
}

char lower(char c)
{
    if ('A' <= c && c <= 'Z')
    {
        c = c + ('a' - 'A');
    }
    return c;
}


int doencrypt(string text, string plaintext)
{
    char texts[strlen(text)];
    string ciphertext = text;

    for (int i = 0; strlen(plaintext) > i; i++)
    {
        if (isupper(plaintext[i]))
        {
            int coverttexttonum = plaintext[i] - 65;
            texts[i] = upper(ciphertext[coverttexttonum]);
        }
        else if (islower(plaintext[i]))
        {
            int coverttexttonum = plaintext[i] - 97;
            texts[i] = lower(ciphertext[coverttexttonum]);
        }
        else
        {
            texts[i] = plaintext[i];
        }
    }
    printf("ciphertext: %s\n", texts);
    return 0;
}