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
int const MX = 2e6+ 10 ;
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
int dx[]= {0,0,-1, -1, -1,1, 1, 1} ;
int dy[] = {-1, 1, 1,0 , -1, 1, 0 ,-1} ;

map < PII , bool > has ;
map< PII , int > dist ;
map < PII , bool > vis ;
int main()
{
    PII fr, to ;
    cin >> fr.F >> fr.S >> to.F >> to.S ;
    int n ;
    cin >> n ;
    for(int i = 0; i < n; i++)
    {
        int r, a , b ;
        scanf("%d %d %d",&r,&a,&b) ;
        for(int j = a ; j <= b; j++)
            has[{r,j}] = 1;
       // cout << bfs(fr) << endl ;
    }
    queue < PII > q ;
        q.push(fr);

        dist[fr] = 0 ;
        while(!q.empty())
        {
          PII u = q.front();
          q.pop() ;

          if(u == to) {
                    cout <<  dist[u] << endl ;
                    return 0 ;
          }

            for(int j = 0 ; j < 8; j++)
            {
                PII tmp ;
                tmp.F = u.F + dx[j] ;
                tmp.S = u.S + dy[j] ;

                if(!vis.count(tmp) && has.count(tmp)){
                    q.push(tmp) ;
                    dist[tmp] = dist[u] + 1 ;

                    vis[tmp] = 1;
                }
            }

        }
     cout << "-1" << endl ;
    return 0 ;
}
