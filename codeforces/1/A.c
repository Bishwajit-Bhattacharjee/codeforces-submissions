#include <stdio.h>
#include <math.h>

int main()
{
    long long int n , m , a, x, y;
    scanf("%I64d %I64d %I64d", &n ,&m , &a);
    x = (n + a - 1)/a;
    y = (m+a -1)/a;
    long long int ans = x * y;
    printf("%I64d", ans);
    return 0;
}
