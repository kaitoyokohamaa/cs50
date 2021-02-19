#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{
    if(argc==2)
    {
    string plainText = get_string("plaintext: ");
    char calc [*argv[1]];
    for(int i = 0,n= strlen(plainText); i<n;i++ )
    {
        if(isalpha(plainText[i]))
        {
            calc[i] =plainText[i]+atoi(argv[1]);
        }
    }
    printf("ciphertext:%s", calc);
    }else
    {
            printf("Usage: ./caesar key");
    }
    printf("%d",argc);
}