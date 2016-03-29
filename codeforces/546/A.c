#include <stdio.h>
int main()
{
    int k, n, w;
    scanf("%d %d %d", &k, &n, &w);
    if(k*w *(w + 1)/2 > n)
      printf("%d\n",k*w *(w + 1)/2 - n );
    else
     printf("0\n");
    return 0;
}
