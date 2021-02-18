#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
void chackCounts(int n);
int main(void)
{
    string text = get_string("Text: ");
    //文字列をカウントする
    int score =0;
    int word=1;
    int sentence=0;
    double L=0;
    double S=0;
    int index=0;
    for(int i = 0; i <= strlen(text); i++)
    {
        // カウントしないタイプチェック
        if(text[i] != '\0' && text[i] != ' ' &&text[i] != '!' &&text[i] != ','&& text[i] != '"' && text[i] != '.'&& text[i] != '?'&& text[i] != ';'&& text[i] != ':'&& text[i] != '-')
        {
             score=score+1;
        }
        else if(text[i] == ' ')
        {
             word=word+1;
        }else if(text[i] == '.')
        {
            sentence=sentence+1;
        }
    }

    L=((double)score/(double)word)*100;
    S=((double)sentence/(double)word)*100;
    // printf("%f",(0.0588 * L )- (0.296 * S) - 15.8);
    index = 0.0588 * (double)L - 0.296 * (double)S - 15.8;
    if(index<0){
        printf("Before Grade 1");
    }else if(index>16){
        printf("Grade 16+");
    }else{
    printf("Grade %d",index);
    }
}
