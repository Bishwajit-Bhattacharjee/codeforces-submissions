#include  <bits/stdc++.h  >
using namespace std ;
int main ()
 {
    int n ,k ,sum = 0;
    cin >>n >> k;
    int c = 0;
    for( int i = 1;i <=n ;i++ )
    {
    sum +=i*5;
    if (sum > 240 -k )
    break ;
    c++;
    
    }
    cout <<c ;
    return 0;
 }