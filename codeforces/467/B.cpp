//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;
#include<iostream>
using namespace std;
int n,m,k,i,a[10005],s;
main()
{
cin>>n>>m>>k;
for(;i<m+1;i++)cin>>a[i];
for(i=0;i<m;i++)
if(__builtin_popcount(a[m]^a[i])<=k)s++;
cout<<s;
}


//int main()
//{

   // return 0;

//}
