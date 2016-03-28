#include <stdio.h>
long long int fab(long long int x){
 if(x >= 0)
   return x;
   else
   return -x;
}
int main()
{
     long long int a, b, s;
     scanf("%I64d %I64d %I64d", &a, &b, &s);
     if(s < fab(a)+ fab(b) || (s - (fab(a)+ fab(b))) %2 == 1)
      printf("No\n");
      else
      printf("Yes\n");

    return 0;
}
