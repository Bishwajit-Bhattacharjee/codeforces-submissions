#include<bits/stdc++.h>
using namespace std;
int n , ara[1000006];
int main()
{

    scanf("%d",&n);
    for(int i=0;i<n;i++) scanf("%d" ,&ara[i] );

    sort(ara,ara+n);
    if( ara[n-1]==1) ara[n-1]=2;
    else ara[n-1]=1;
    sort(ara,ara+n);
    for(int i=0;i<n;i++) printf("%d ", ara[i]);
    return 0;
}
