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
    printf("%d\n",score);
    printf("%d\n",word);
    printf("%d\n",sentence);
    
    return score;
}
