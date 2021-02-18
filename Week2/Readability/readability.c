#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
void chackCounts(int n);
int main(void)
{
    string text = get_string("Text: ");
    //文字列をカウントする

    int score =0;
    int word=1;
    int sentence=0;
    float L=0;
    float S=0;
    int index=0;
    for(int i = 0; i <= strlen(text); i++)
    {
        // カウントしないタイプチェック
        if(isalnum(text[i]) != 0 )
        {
             score=score+1;
        }
        else if( isspace(text[i]) != 0 )
        {
             word=word+1;
        }else if(text[i] == '.' ||text[i] == '!'||text[i] == '?' ||text[i] == ':' )
        {
            sentence=sentence+1;
        }
    }
    L=(double)score/(double)word*100;
    S=(double)sentence/(double)word*100;
    index = round(0.0588 * (double)L - 0.296 * (double)S - 15.8);

    if(index<0){
        printf("Before Grade 1\n");
    }else if(index>16){
        printf("Grade 16+\n");
    }else{
    printf("Grade %d",index);
    printf("\n");
    }
}
