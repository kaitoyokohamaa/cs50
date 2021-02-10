#include<cs50.h>
#include<stdio.h>


void makeBlock(int n)
{
    if(n<8)
    {
        for (int i = 0; i ==n||i<n; i++)
    {
        printf("%s","#");
    }
        printf("%s","\n");
    }
}

int get_positive_int(void);

int main(void)
{
    int i = get_positive_int();
  for(int j=0;j<i;j++)
    {
      makeBlock(j);
    }

}

// Prompt user for positive integer
int get_positive_int(void)
{
    int height;
    do
    {
        height = get_int("height: ");
    }
    // もし高さより1の方が大きかったらもう一度ループする
    while (height < 1);
    return height;
}
