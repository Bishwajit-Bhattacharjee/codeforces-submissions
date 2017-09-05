#include <bits/stdc++.h>

using namespace std ;
int const MX = (int)1e6 + 10 ;
vector < int >  divi[MX] ;

int main()
{
    vector < long long > v(MX) , c(MX, 0LL);
    for(int i = 1; i <= MX ; i++)
        c[i] = c[i-1]^ i;

    int n ;
    cin >> n ;
    long long ans = 0LL;
    for(int i = 1; i <= n ;i++){
        long long tmp ;
        scanf("%I64d", &tmp);
        ans ^= ( (n / i) & 1LL)?(tmp ^ c[n % i] ^ c[i-1]) : (tmp ^ c[n % i]);
    }

    cout << ans ;
}
