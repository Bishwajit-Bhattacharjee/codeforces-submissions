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
int const mod = 10000007;
using namespace std;
inline long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************
struct node {
   int  x ; int w;
   bool operator <(const node &a) const {
       return w < a.w ;
   }
};

vector < int > adj[1010];
 //******************************************************************************************************************************
int main()
{
    priority_queue < node > pq;
    int a[1001];
    int n, m;
    cin >> n >> m;
    for(int i = 0;i < n; i++){
        int t;
        scanf("%d", &t) ;
        node tmp ;
        tmp.x = i + 1 ;
        tmp.w = t;
       a[i+1] = t ;
       pq.push(tmp);
    }
    for(int i = 0 ; i < m; i++){
        int p , q ;
        cin >> p >> q ;
        adj[p].pb(q) ;
        adj[q].pb(p);
    }
    ll  ans  = 0;
    while(!pq.empty()){
        node tmp = pq.top() ;
        pq.pop();
        for(auto t: adj[tmp.x]){
            ans += (ll)a[t];

        }
        a[tmp.x] = 0;
    }
    cout << ans << endl;

   return 0;
}



