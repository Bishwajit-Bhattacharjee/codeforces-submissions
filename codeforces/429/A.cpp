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


ll bigmod(ll base, ll pow){
   if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}

//*****************************************//

int const MX =   1e5 + 10;

int frm[MX] , to[MX] ;
vector < int > adj[MX] ;
vector < int > ans ;
bool vis[MX];

void dfs(int node , int even, int odd, int level ){
    
    vis[ node ] = 1;
    
    if(level & 1){ // odd depth 
        if(to[node] == frm[node]){
            if( odd & 1 ){
                ans.pb(node);
                odd++ ;
            }
        }
        else {
            if( (odd & 1 ) == 0 ){
                
                ans.pb(node);
                odd++;
            }
        }
    }
    else {
        if(frm[node] == to[node]){
            if(even & 1){
                ans.pb(node);
                even++;
            }
        }
        else {
            if( (even & 1 ) == 0) {
                ans.pb(node);
                even++;
            }
        }
    }
    
    for(auto i : adj[node]){
        if(!vis[i]){
            dfs( i , even, odd , level + 1 ) ;
        }
    }
}


int main()
{
    int n;
    cin >> n ;
    for(int i = 0 ; i < n - 1; i++){
        int u , v ;
        scanf("%d %d", &u , &v);
        adj[u].pb(v) ;
        adj[v].pb(u) ;
    }
    
    for(int i = 1; i <= n; i++){
        scanf("%d ", &frm[i]);
    }
    for(int i = 1; i <= n ; i++){
        scanf("%d", &to[i]);
    }
    dfs(1, 0 , 0 , 1 );
    cout << ans.size() << endl;
    
    for(int i = 0 ;i < ans.size() ; i++){
        printf("%d\n", ans[i]);
    }
    return 0;
    
}