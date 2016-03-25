#include <stdio.h>
int main()
{
    int a, b, c, i;
    int cmp[6];
    scanf("%d %d %d", &a, &b, &c);
    cmp[0] = a *(b + c);
    cmp[1] = a + ( b  * c);
    cmp[2] = a *  b *  c;
    cmp[3] = (a +  b) *  c;
    cmp[4] = (a *  b) +  c;
    cmp[5] = a + b + c;
    int max = cmp[0];
    for(i = 1; i < 6; i++){
        if(cmp[i]> max)
            max = cmp[i];
    }
    printf("%d", max);
    return 0;
}
