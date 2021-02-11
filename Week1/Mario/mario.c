#include<cs50.h>
#include<stdio.h>

 int height;
void makeBlock(int n)
{
    int makeHeight= height;
    // ここでブロックを作成する→やりたいことは逆さまにする。例えばブロックの数が＃＃なら.を一つにする
        if(n>0||n==0)
        {
        for(int g = n;g<makeHeight;g++)
        {
            // printf("%d", g);
             printf(" ");
        }
        }
    // ここで変数数分のループしたブロックを作成する
        for (int i = 0; i ==n||i<n ; i++)
        {
            printf("#");
        }
        printf("%s","\n");
}

int get_positive_int(void);

int main(void)

{
    // 関数heightをここで呼び出す
    int i = get_positive_int();
    // 変数分だけルーブする
    for(int j=0;j<i;j++)
    {
        makeBlock(j);
    }
}

// Prompt user for positive integer
int get_positive_int(void)
{

    do
    {
        height = get_int("height: ");
    }
    // もし高さより1の方が大きいかつ8以上だったらもう一度ループする
    while (height < 1 || height > 8);
    return height;
}



