#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main(void)
{
    float makeChange=get_float("makeChange: ");
    int cents = round(makeChange * 100);
    int change = 0;
    do{
    if(makeChange>=25){
        change= change+1;
        makeChange=makeChange-25;
    }
     else if(makeChange>=10 && makeChange<=25 )
    {
        // 10セント以上25セント未満の場合は10セントのお釣りを返す。
        change= change+1;
         makeChange=makeChange-10;
    }else if(10>=makeChange&&5<=makeChange)
    {
        // 10セント未満5セント以上の場合は5セントのお釣りを返す
        change= change+1;
        makeChange=makeChange-5;
    }
    else if(5>=makeChange&&0<=makeChange)
    {
        // 5セント未満1セント以上であれば0-5の間でペニーを返す
        change= change+1;
        makeChange=makeChange-1;
    }
        }
    while (makeChange >0);
    printf(" %d \n",change);
}