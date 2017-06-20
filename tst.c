#include<stdio.h>
int fun(int n)
{
    int sum = 0,i;
    for(i = 0;i<n;i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
   int i = 0;
   long result = 0;
   for(i = 1;i<=100;i++)
   {
       result+=i;
   }
    printf("result[1-100]=%ld \n",result);
    printf("result[1-250]=%d \n",fun(250));
    
}
