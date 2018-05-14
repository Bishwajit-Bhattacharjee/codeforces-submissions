#include <bits/stdc++.h>

using namespace std;
int const MX = 2e5 + 100;
typedef long long int ll;

int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;

    long long ara[MX] ;
    ll n , m ;
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        cin >> ara[i] ;

    ll till = 0;
    ll ans = 1;

    for(int i = 0; i < m ; i++)
    {
        ll tmp ;
        cin >> tmp;
        while(ans <= n && (till + ara[ans] < tmp ) )
             till += ara[ans++] ;
        cout << ans << ' ' <<  tmp  - till << endl;
    }

    return 0;
}
