#include <stdio.h>
int main()
{
    int t, a, n;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d",&a);
        n = 0;
        if(360 % (180-a) == 0)
        {
            n = 360 / (180 - a);
        }
        if( n > 2)
            printf("YES\n");
        else 
           printf("NO\n");
    }
    return 0 ;
}