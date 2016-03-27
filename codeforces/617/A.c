#include <stdio.h>
int main()
{
    int x;
    int i;
    int count = 0;
    scanf("%d", &x);
    for(i = 5; x!=0; i--)
    {
        count += x / i;
        x = x % i;

    }
    printf("%d\n", count);
    return 0;
}
