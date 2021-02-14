#include<cs50.h>
#include<stdio.h>

// 高さの変数宣言→javascriptならletみたいなノリ
int height;
// 関数を変数として扱う
int get_positive_int(void);
// 変数で入力した高さ分のブロック作り
void makeBlock(int n)
{
    int makeHeight= height;
        if(n > 0)
        {
        for(int g = n; g < makeHeight ; g++)
        {
             printf(" ");
        }
        }
        for (int i = 0;i<n ; i++)
        {
            printf("#");
        }
        printf("%s","\n");
}
// 1以上8未満はNGですよ
int get_positive_int(void)
{
    do
    {
        height = get_int("height: ");
    }
    while (height < 1 || height > 8);
    return height;
}
// 変数数のループを作るために値を渡してます
int main(void)
{
    int i = get_positive_int();
    for(int j = 0 ; j <= i ; j++)
    {
        makeBlock(j);
    }
}