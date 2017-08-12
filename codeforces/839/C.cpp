//HK HK HK HK HK 108 times


#include <bits/stdc++.h>
#define PII pair < int , int >
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

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
int const mod = 1000000007 ;
using namespace std;
 long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************



 //******************************************************************************************************************************


ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}

//*****************************************
bool vis[100010];
vector < int > adj[100010];
int n ;

double dfs(int i)
{
    if(adj[i].size() == 1 && i != 1){
        return 1.0;
    }
    vis[i] = 1;
    double r = 0.0;
    int cnt = 0;
    for(int j =0 ; j < adj[i].size(); j++){
        if(!vis[adj[i][j]]){
            cnt++;
            r += dfs(adj[i][j]) ;
        }
    }
    r /= cnt ;

    return (i == 1)? r : r + 1.0;
}

int main()
{
    cin >> n;
    for(int i = 0; i < n - 1; i++){
        int t1, t2;
        scanf("%d %d", &t1, &t2);
        adj[t1].pb(t2) ;
        adj[t2].pb(t1);
    }
    if(n == 1 ){
        cout << "0" << endl;
    }
    else
    printf("%.15f\n", dfs(1));

    return 0;
}
