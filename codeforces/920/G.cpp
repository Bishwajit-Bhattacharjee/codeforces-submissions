#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()
#include <chrono>

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1 % MOD;
    ll x = bigmod(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e6 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vector < int > pf[N];
bool mark[N] ;

void seive()
{
    for(ll i = 2; i < N; i++){
        if(!mark[i]){
            for(int j = i; j < N; j += i )
            {
                if(j != i ) mark[j] = 1;
                pf[j].push_back(i);
            }
        }
//        if(!mark[i])
//        {
//            for(ll j = i*i; j < N ; j += i * i )
//                wont[j] = 1;
//        }
    }
}

//ll fact[N] ;
ll n, k;
ll comCount(ll num)
{
    return (bigmod(num, n ))  ;
}

vector < int > needed ;


void do_it_babe(int pr, int pos,int so_far)
{
    if(pf[pr].size() == pos) {
        if(so_far != 1)
            needed.push_back(so_far);
        return ;
    }
    do_it_babe(pr,pos+1,so_far * pf[pr][pos]);
    do_it_babe(pr,pos+1,so_far);
}

ll Count(ll num)
{
    ll notans = 0;

    for(auto x : needed)
    {
        notans += (num/x) * ( (pf[x].size() % 2 == 0) ? -1 : 1 ) ;
    }
    assert(num - notans >= 0);
    return num - notans ;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    seive();

    ll t;
    cin >> t;
    while(t--)
    {
        ll x,p,k;
        cin >> x >> p >> k;
        needed.clear();
        do_it_babe(p,0,1);

        int nd = Count(x);
        k += nd;

        ll lo = 1, hi = 1e13;
        ll ans = hi;

        while(lo <= hi)
        {
            ll mid = (lo + hi) / 2;

            if(Count(mid) >= k) {
                ans = min(ans,mid);
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
