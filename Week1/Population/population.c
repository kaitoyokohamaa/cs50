#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while(start < 9);
    // TODO: Prompt for end size
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while(end <=start );
    // TODO: Calculate number of years until we reach threshold
    int n= start + (start/3)-(start/4);
    int yerars=0;
    // 一年目だと1200を入力したら100増えるが二年目はそこから人口削減をしないといけない
    // だからループ文を使ってnが変更するたびに✖割り算をする値を毎回変えないといけない。
    do
    {
        for(int i=0;n<end;i++)
        {
            n=n+(n/3)-(n/4);
            yerars=1+i;
        }
    }
    while(n<=end);
    // TODO: Print number of years
    printf("Years: %d" ,yerars+1);
}


#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    // TODO: Prompt for start size
    int startSize;
    do
    {
        startSize = get_int("Start size: ");
    }
    while (startSize < 9);
    // TODO: Prompt for end size
    int endSize;
    do
    {
        endSize = get_int("End size: ");
    }
    while (endSize < startSize);
    // TODO: Calculate number of years until we reach threshold

    int years = 1;
    int n = startSize + floor((double)startSize / (double)3) - floor((double)startSize / (double)4);
    if (n < endSize)
    {
        do
        {
            years++;
            n  =  n + floor((double)n / (double)3) - floor((double)n / (double)4);
        }
        while (n < endSize);
    }
    else if (endSize == startSize)
    {
        years = 0;
    }
    // TODO: Print number of years
    printf("Years: %d", years);
}