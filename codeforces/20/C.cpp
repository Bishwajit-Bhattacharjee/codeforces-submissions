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
int const MX =   1e5 + 10;

struct node{
    int at;
    ll cost ;
    
    
};

bool operator<(node a, node b ){
    return a.cost > b.cost ;
}
struct edge{
    int v ;
    ll w ;
    
};
int par[MX] ;
ll dist[MX] ;
vector < edge > adj[MX] ;
priority_queue < node > pq;
 
void print(int now){
    if(par[now] != now ){
        print(par[now]) ;
       
    }
    printf("%d ", now );
 }
int main()
{
    int n, m  ;
    cin >> n >> m ;
    
    for(int i = 0; i < m ;i++){
        ll u , v, w ;
        scanf("%I64d %I64d %I64d", &u , &v, &w);
        adj[u].pb((edge){v, w});
        adj[v].pb((edge){u , w});
        
    }   
    par[1] = 1;
    fill(dist + 1 , dist + n + 1 , (ll)1e15 );
   
    dist[1] = 0;  
    pq.push((node){1, 0});
    while(!pq.empty()){
        node tmp = pq.top();
        pq.pop() ;
        
        if(tmp.cost != dist[tmp.at]) {
            continue ;
        }
        for(edge i: adj[tmp.at]){
            if(dist[i.v] > tmp.cost + i.w){
                dist[i.v] = tmp.cost + i.w;
                pq.push((node){i.v, dist[i.v]}) ;
                par[i.v] = tmp.at ;
            }
        }
    }
    if(dist[n] == (ll)1e15){
        puts("-1") ;
        return 0;
    }
  //  printf("1 ") ;
    print(n);
   // cout << par[n] << endl ;
    //cout << dist[n] << endl;
    return 0 ;
}
