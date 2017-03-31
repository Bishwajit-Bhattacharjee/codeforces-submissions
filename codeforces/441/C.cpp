#include<stdio.h>
int main()
{
    int n,m,k,bty=0;
    scanf("%d %d %d",&n,&m,&k);
    int i,x=0,y=0,j,ch[305][305]={0},q=0;
    for(i=0;i<k-1;++i)
    {
        printf("2 ");
        bty+=2;
        int w=0;
        for(j=0;j<2;++j)
        {
            printf("%d %d ",x+1,y+1);
            if(q==0)
            {
                ++y;
                if(y<m)
                    ;
                else
                {
                    ++x;
                    q=1;
                    y=m-1;
                }
            }
            else
            {
                --y;
                if(y>=0)
                    ;
                else
                {
                    ++x;
                    q=0;
                    y=0;
                }
            }
        }
        printf("\n");
    }
    printf("%d ",n*m-bty);
    while(bty!=n*m)
    {
        ++bty;
        printf("%d %d ",x+1,y+1);
        if(q==0)
        {
            ++y;
            if(y<m)
                ;
            else
            {
                ++x;
                q=1;
                y=m-1;
            }
        }
        else
        {
            --y;
            if(y>=0)
                ;
            else
            {
                ++x;
                q=0;
                y=0;
            }
        }
    }
    return 0;
}