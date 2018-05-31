#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define PII pair<long long,long long>

using namespace std;
using namespace __gnu_pbds;
typedef tree<
PII,
null_type,
less<PII>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

typedef long long ll;
int const MX = 1e5 + 10;

ordered_set rleft, rRight;
ll ara[MX] ;

ll invrRight(int pos)
{
    ll c1 = rRight.order_of_key({ara[pos], pos}) ;
    ll c2 = rleft.order_of_key({ara[pos], pos}) ;
    return c1 + rleft.size() - c2 ;
}

ll invrleft(int pos)
{
    ll c1 = rRight.order_of_key({ara[pos], pos}) ;
    ll c2 = rleft.order_of_key({ara[pos] , pos}) ;
    c2 = rleft.size() - c2 - 1;
    return c1 + c2;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin) ;
#endif
    ll n,k;
    cin >> n >> k;
    for(int i = 0; i < n;i++)
        cin >> ara[i] ;
    ll cunt = 0;

    for(int i = n - 1; i >= 0 ; i--)
    {
        cunt += invrRight(i) ;
        rRight.insert({ara[i], i}) ;

    }
    if(cunt  <= k )
    {
        cout << n *(n-1) / 2 << endl;
        exit(0) ;

    }
    rRight.clear();

    for(int i = 0; i < n -1 ; i++)
        rleft.insert({ara[i], i});
    cunt -= invrRight(n-1) ;

    //rRight.insert({ara[n-1], n-1}) ;
    ll ans = 0LL;

    int l = n - 2;//r = n - 1;
    for(int r = n - 1; r > 0; r--)
    {
        cunt += invrRight(r) ;
        rRight.insert({ara[r], r}) ;

        while(l >= 0 && cunt > k )
        {
            cunt -= invrleft(l) ;
            rleft.erase({ara[l], l}) ;
            l--;

        }
        ans += rleft.size() ;
    }
    cout << ans << endl;

    return 0;
}
