#include <bits/stdc++.h>
using namespace std;
int const N = 21;
int a[1<<N];
int r[1<<N];
typedef long long int ll;
#define debug(x) cout << #x << ": " << x << endl
ll forw[N], rev[N] ;

int n;

ll inv_cnt(int lvl,int ara[],ll cnt[],int l,int r)
{
    if(l == r)
        return 0;
    int mid = (l+r)/2;
    ll invHere = 0;
    inv_cnt(lvl+1,ara,cnt,l,mid) ;
    inv_cnt(lvl + 1,ara,cnt,mid+1,r);

    int tmp[r-l+1] ;

    int id = 0;
    int i1 = l, i2 = mid+1;

    while(i1 <= mid and i2 <= r)
    {
        if(ara[i1] > ara[i2])
            tmp[id++] = ara[i2++];
        else
            invHere += (i2-mid-1), tmp[id++] = ara[i1++];
    }
    while(i1 <= mid)
    {
        invHere += (i2 - mid - 1);
        tmp[id++] = ara[i1++];
    }
    while(i2 <= r)
        tmp[id++] = ara[i2++] ;

    for(int i = l ; i <= r; i++)
        ara[i] = tmp[i-l] ;

    cnt[lvl] += invHere;
    return invHere;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;

    for(int i = 0; i < (1 << n); i++)
        cin >> a[i] , r[i] = a[i] ;
    reverse(r,r+(1<<n));

    inv_cnt(0,a, forw, 0,(1<<n)-1);

    inv_cnt(0,r,rev, 0,(1<<n) - 1) ;
    int q;
    cin >> q;

    while(q--)
    {
        int a;
        cin >> a ;
        a = n - a;
        for(int i = a; i <= n; i++)
        {
            swap(forw[i], rev[i]);
        }
        ll ans = 0;

        for(int i = 0; i <= n; i++)
            ans += forw[i] ;
        cout << ans << '\n';
    }
    return 0;
}
