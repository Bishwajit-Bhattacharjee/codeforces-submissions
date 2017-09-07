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

int const MX = 500;

int G[MX][MX] ;
bool vis[MX][MX] ;
int par[MX] ;

bool marked[MX] ;
int find(int u ){
   return (par[u] == u)? u : par[u] = find(par[u]) ;
}
void Union(int u , int v){
    int U = find(u) ;
    int V = find(v) ;
    if(U != V){
        par[U]  = V ;
        vis[u][v] = vis[v][u] = 1 ;

    }
}
int main()
{
  int n, m  , k ;
  cin >> n >> m >> k ;
  if(k == n or( m >  ( (n * (n - 1 ) / 2 ) - k +  1)) ) {
    puts("-1");
    return 0;
  }
  int a[MX] ;
  for(int i = 1 ;i <= n; i++)
      par[i] = i;

  for(int i = 0 ; i<k ; i++)
    scanf("%d", &a[i]) , marked[a[i]] = 1 ;
  int tmp1= a[0] , tmp2= a[1] ;
  int inter ;
  for(int i = 1 ;i <= n; i++){
  //  for(int j = 0; j < k ;j++){
        if(i != tmp1 && i != tmp2 && !marked[i]){

            inter = i ;
            break ;
        }
    //    }
    }
  //  cout << "inter" << ' ' << inter << endl;

    m -= 2 ;

    printf("%d %d\n",tmp1 , inter);
    Union(tmp1 ,inter);

    printf("%d %d\n",tmp2 , inter );
    Union(tmp2 , inter );

    vis[tmp1][inter] = 1, vis[inter][tmp1] = 1 ;
    vis[tmp2][inter] = 1 , vis[inter][tmp2] = 1;
    for(int i = 1; i <= n; i++){
        if(i != tmp1 && !marked[i] && m && !vis[i][tmp1]){
            m-- ;
            Union(i , tmp1) ;
            printf("%d %d\n", i , tmp1);
            vis[tmp1][i] = 1;
            vis[i][tmp1] = 1;

        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
           if(m && !vis[i][j] && i != j && i != tmp1 && j != tmp1 ){
                if(find(i) != find(j)){
                    printf("%d %d\n", i , j ) ;

                    Union(i , j) ;
                    m--;

                }
           }
        }
    }


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(m && !vis[i][j] && i != j && i != tmp1 && j != tmp1 ){
                printf("%d %d\n", i , j );
                vis[i][j] =1 ;
                vis[j][i] = 1 ;
                m--;
            }
        }
    }
    return 0 ;
}




