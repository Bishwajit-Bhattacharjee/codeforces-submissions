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

int const N = 2e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector < int > g[N] ;
int par[N] ;

void merge(int a,int b)
{
    a = par[a] ;
    b = par[b] ;
    if(a == b ) return ;
    if(g[a].size() < g[b].size())
        swap(a,b);

    while(!g[b].empty())
    {
        par[g[b].back()] = a;
        g[a].push_back(g[b].back());
        g[b].pop_back();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++)
        par[i] = i, g[i].push_back(i);

    for(int i = 1; i <= n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        merge(a,b);
    }
    for(int i = 1; i < N ; i++)
    {
        for(auto x : g[i]){
            cout << x << " " ;
        }
    }
    cout << endl;
    return 0;
}
