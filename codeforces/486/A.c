#include <stdio.h>
int main()
{
   long long int n;
   scanf("%I64d", &n);
   if(n % 2 == 0)
    printf("%I64d\n", n /2);
   else
    printf("%I64d\n", n/2 - n);
   return 0;
}
