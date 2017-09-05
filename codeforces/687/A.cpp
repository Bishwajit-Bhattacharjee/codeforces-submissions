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
int const MX = (1e5 + 10);

vector < int > G[MX] ;
vector < int > ans[3] ;
int C[MX] ;
bool vis[MX] ;
int main(){
    int n, m ;
    cin >> n >> m ;

    for(int i = 0 ; i < m; i++){
        int t1 , t2 ;
        scanf("%d %d", &t1, &t2 );
        G[t1].pb(t2) ;
        G[t2].pb(t1) ;

    }
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            queue < int > q ;

            int color = 0 ;
            C[i] = color ;
            vis[i] = 1;
            ans[color].pb(i) ;
            q.push(i) ;
            while(!q.empty()){
                int now = q.front();
                q.pop();

                for(auto j : G[now]){
                    if(vis[j]){
                       if(C[j] == C[now]){
                          puts("-1") ;
                          return 0;
                       }
                    }
                    else {
                        vis[j] = 1;
                        C[j] = C[now] ^ 1 ;
                        ans[C[j]].pb(j);
                        q.push(j);

                    }
                }
            }



        }

    }
    cout << ans[0].size() << endl;
    for(auto i : ans[0]) printf("%d ", i);
    printf("\n");
    cout << ans[1].size() << endl;
    for(auto i : ans[1]) printf("%d ", i);

    return 0;
}
