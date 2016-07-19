#include <cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std ;

#define REP(i,a,b) for(int i=int(a);i<=int(b);i++)
typedef long long int ll;

int abs(int a,int b)
{
    if(a<b) return (b-a);
    else return (a-b);
}
int main()
{
    int n,b,i;int ara[200006];
    char str[200006];
    scanf("%d",&n);

    scanf("%s",str);

    REP(i,0,n-1)
    {
        scanf("%d",&ara[i]);
    }
    int t_min =1000000000;
    for(i=0;i<n-1;i++)
    {
      if(str[i]=='R'&& str[i+1]=='L')
        t_min=min(t_min,((ara[i+1]-ara[i])/2));
    }
    if(t_min==1000000000)
        printf("-1\n");
    else
        printf("%d\n",t_min);



    return 0;
}
