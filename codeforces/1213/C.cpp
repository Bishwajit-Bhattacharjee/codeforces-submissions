#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        ll n,m, ans =0;
        ll ara[10] ;
        cin >> n >> m;
        memset(ara,0,sizeof ara);
        ll tot = 0;
        for(int i = 0; i <= 9; i++){
            ara[i] = (i * m) % 10;
            tot += ara[i] ;
        }    

        ans = (n/m) / 10 * tot;
        int left =  (n/m)%10 ;

        for(int i = 0; i <= left; i++)
            ans += ara[i] ;
        cout << ans << '\n';

    }
    return 0;
}