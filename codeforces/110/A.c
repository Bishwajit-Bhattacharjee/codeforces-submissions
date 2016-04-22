#include <stdio.h>
#include <math.h>

void main()
{
    long long int num;
    scanf("%I64d", &num);
    //int digit = floor(log10(num*1.0))+1;
    char c='0';
    int digit=0;
    while(num != 0)
    {
        if(num % 10 == 4 || num % 10 == 7)
        {
            digit++;
        }
        num = num/10;
    }
    if(digit == 4 || digit == 7)
        printf("YES\n");
    else
        printf("NO\n");
}
