/*
http://codeforces.com/problemset/problem/271/A
*/
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    int n1;
    int d[4];
    /*for(i=3;i>=0;i--){
        d[i]=n%10;
        n=n-d[i];
        n=n/10;
    }*/
    //for(i=0;i<4;i++)printf("\n%d",d[i]);
    int t   ;
    while(++n){
         t = n;
        n1=t;

        for(i=3;i>=0;i--){
            d[i]=t%10;
            t=t-d[i];
            t=t/10;
        }
        if(d[0]!=d[1] && d[0]!=d[2] && d[0]!=d[3] && d[1]!=d[2] && d[1]!=d[3] && d[2]!=d[3] ){
            printf("%d",n1);
            return 0;
        }
    }
}
