#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, string argv[])
{

    char *ascii = argv[1];
    if(atoi(argv[1]) &&argc==2 &&isdigit(ascii[0])&& !isalpha(ascii[0]))
    {
    string plainText = get_string("plaintext: ");
    char calc [222];
    char box[111];
    for(int i = 0,n= strlen(plainText); i<n;i++ )
    {
        if(isalpha(plainText[i]))
        {
            if(isupper(plainText[i]))
            {
                if((plainText[i])==90)
                {
                    // upperbox[i]=plainText[i]-65;
                    calc[i]=box[i]+atoi(argv[1])%26 + 65;
                }
                else
                {
                calc[i] =plainText[i]+atoi(argv[1]);
                }
            }
            else if(islower(plainText[i]))
            {
                if((plainText[i])==122)
                {
                    // lowerbox[i]=plainText[i]-97;
                    calc[i]=box[i]+atoi(argv[1])%26 + 97;
                }
                else
                {
                calc[i] =plainText[i]+atoi(argv[1]);
                }
            }
        }
    }
       printf("ciphertext:%s",calc );
    }else if(!atoi(argv[1]) || argc!=2 ||!isdigit(ascii[0]) )
    {
            printf("Usage: ./caesar key");
    }
}