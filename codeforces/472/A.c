#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    if(n % 2== 0)
        printf("%d %d\n",8, n -8);
    else
        printf("%d %d\n", 9, n-9);
    return 0;
}
