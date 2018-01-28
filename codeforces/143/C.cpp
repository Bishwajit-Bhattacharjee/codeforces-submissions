#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
    ll a, b, c, n ;
    ll mx, mn ;
    mx = -1, mn = 1e18;
    ll ara[4];
    cin >> n;
    for(ll a = 1; a * a * a <= n; a++)if(n % a == 0){
        for(ll b = 1; b * b <= n/a ; b++)if(n/a % b == 0){
            c = n/a/b;
            ara[0] = a, ara[1] = b, ara[2] = c;
            sort(ara, ara + 3) ;
            do{
                ll t1 = ara[0] * ara[1] *ara[2];
                ll t2 = (ara[0] + 1) * (ara[1] + 2) * (ara[2] + 2);
                t2 -= t1;
                mx = max(mx, t2);
                mn = min(mn,t2) ;
            }while(next_permutation(ara,ara+3));
        }
    }
    cout << mn << ' ' << mx << endl;
    return 0;
}
