#include <stdio.h>

int main()
{
    int a, b, maxi,m,n,c_m=0,c_c=0;
    scanf("%d",&n);
    while(n--)
    {
        scanf("%d %d",&a, &b);
        if(a > b) c_m++;
        else if(a < b) c_c++;
        else 
          continue;
          
    }
    if(c_m > c_c) printf("Mishka\n");
    else if(c_m < c_c) printf("Chris\n");
    else 
       printf("Friendship is magic!^^\n");
    return 0;
}