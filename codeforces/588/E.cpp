//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PLL pair < ll, ll >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7 ;
long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}

int const N = 2e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int const LOG = 19;
int const SZ = 10;
vector < int > emx[N][LOG+1];
int sp[N][LOG+1];
int lvl[N];
vector < int > g[N];
vector < int > person[N] ;


void dfs(int n,int pr,int l)
{
    lvl[n] = l;
    sp[n][0] = pr;

    for(auto x : g[n])
    {
        if(x != pr)
        {
            dfs(x,n,l+1);
            emx[x][0] = person[n];
        }
    }
}

vector <int> Merge(vector < int > &v1, vector < int> &v2)
{
    vector < int > tmp(v1);

    for(auto x : v2)
        tmp.push_back(x);
    sort(tmp.begin(),tmp.end());

    while(tmp.size() > 10)
        tmp.pop_back();
    return tmp;
}

vector < int > Q(int u,int v)
{

    if(lvl[u] < lvl[v]) swap(u,v);

    vector < int > ans;
    ans = person[u] ;
    //cout << ans.size() << endl;
    for(int i = LOG; i >= 0; i--)
    {
        if( ( lvl[u] - (1<<i) )>= lvl[v])
        {
            ans = Merge(ans, emx[u][i]);
            u = sp[u][i] ;
        }
    }
    //cout << u << " " << v << " " << ans[0] << " " << ans[1] << endl;
    if(u == v)
    {
        return ans;
    }
    ans = Merge(ans,person[v]);

    for(int i = LOG; i >= 0; i--)
    {
        if(sp[u][i] != -1 and sp[u][i] != sp[v][i])
        {
            ans = Merge(ans, emx[u][i]);
            ans = Merge(ans, emx[v][i]);
            u = sp[u][i];
            v = sp[v][i];
        }
    }
    return Merge(ans,emx[u][0]);

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m , q;
    cin >> n >> m >> q;

    for(int i = 0; i < n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    for(int i = 1; i <= m; i++)
    {
        int a;
        cin >> a;
        person[a].push_back(i);
    }

    for(int i = 1; i <= n; i++)
    {
        sort(person[i].begin(),person[i].end());
        while(person[i].size() > 10)
            person[i].pop_back();
//
//        cout << i << " :";
//        for(auto x : person[i])
//            cout << x << endl;
    }

    dfs(1,-1,0);

//    for(int i = 1; i <= n; i++)
//    {
//
//        cout << i << " :";
//        for(auto x : emx[i][0])
//            cout << x << " " ;
//        cout << endl;
//    }

    for(int p = 1; p <= LOG; p++)
    {
        for(int i = 1; i <= n;i++)
        {
            if(sp[i][p-1] != -1)
            {
                int up = sp[i][p-1];
                sp[i][p] = sp[up][p-1];
                emx[i][p] = Merge(emx[i][p-1], emx[up][p-1]);
            }
        }
    }

//
//    for(int i = 1; i <= n; i++)
//    {
//
//        cout << i << " :";
//        for(auto x : emx[i][1])
//            cout << x << " " ;
//        cout << endl;
//    }

    while(q--)
    {
        int u,v,a;
        cin >> u >> v >> a;
        vector < int > ans;
        if(u == v ) {
            ans = person[u] ;
        }

        else
            ans = Q(u,v);

        //cout << ans.size() << endl;

        while(ans.size() > a)
            ans.pop_back();

        cout << ans.size() ;
        for(int x : ans) cout << " " << x ;
        cout << '\n';
    }
    return 0;
}
