#include <bits/stdc++.h>
using namespace std;

inline int cil(int n, int a){
    return (n+a-1)/a;
}
int main()
{
    int n , m ;
    cin >> n >> m;
    if(n > m ) swap(n,m);
    if(n ==1 ) {
        cout << m << endl;

    }
    else if(n == 2){
        cout << m/4 * 4 + min(2,m % 4) * 2 ;
    }
    else
        cout << ( n * m + 1)/2  ;

    return 0;
}
