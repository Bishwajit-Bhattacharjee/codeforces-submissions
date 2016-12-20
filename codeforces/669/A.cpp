#include <stdio.h>
int main()
{
    int n, ans , x;
    scanf("%d", &n);
    if(n % 3 == 0) x = 0;
    else
    x = 1;
    ans = ( n /3 ) * 2 + x ;
    printf("%d\n",ans);
    return 0;
}