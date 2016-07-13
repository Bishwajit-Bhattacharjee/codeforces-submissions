#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int a,b;
    scanf("%d",&a);
    int x[a];
    for(int i=0;i<a;i++)
        scanf("%d",&x[i]);
    scanf("%d",&b);int y[b];
    for(int i=0;i<b;i++)
        scanf("%d",&y[i]);
    bool cumul[101]={false};
   // memset(cumul,0,sizeof cumul);

    for(int i=0;i<a;i++)
    {
        if(cumul[x[i]]== false)
            cumul[x[i]]=true;
    }
     for(int i=0;i<b;i++)
    {
        if(cumul[y[i]]== false)
            cumul[y[i]]=true;
    }
    int sum = 0;
    for(int i=0;i<101;i++)
    {
        if(cumul[i]==true)
             sum+=i;
    }
    if(((n*(n+1)/2)-sum)==0)
        printf("I become the guy.\n");
    else
        printf("Oh, my keyboard!\n");
    return 0;
}
