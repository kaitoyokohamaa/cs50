#include<cs50.h>
#include<stdio.h>
#include<math.h>
int main(void)
{
    float makeChange=get_float("Change owed: ");
    int cents = round(makeChange * 100);
    int change = 0;
    do{
    if(cents>=25){
        change= change+1;
        cents=cents-25;
    }
     else if(cents>=10 && cents<=25 )
    {
        // 10セント以上25セント未満の場合は10セントのお釣りを返す。
        change= change+1;
         cents=cents-10;
    }else if(10>=cents&&5<=cents)
    {
        // 10セント未満5セント以上の場合は5セントのお釣りを返す
        change= change+1;
        cents=cents-5;
    }
    else if(50>=cents&&0<=cents)
    {
        // 5セント未満1セント以上であれば0-5の間でペニーを返す
        change= change+1;
        cents=cents-1;
    }
        }
    while (cents >0);
    printf(" %d \n",change);
}