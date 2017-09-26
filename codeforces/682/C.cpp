#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 1e5 + 10 ;
ll const MOD =  1000000007  ;
vector < pair < int , ll >  > G[MX] ;
ll a[MX] ;
int ans;
bool vis[MX] ;

void dfs(int i , ll now ,  bool tkn)
{
    vis[i] = 1;
    if(tkn)
        ans++ ;
    else if(now > a[i])
        ans++ , tkn |= 1 ;
    for(auto j : G[i]){
        if(!vis[j.F]) {
           // cout << j.F << ' ' << j.S << endl ;

            dfs( j.F , max(now +  j.second , j.second) , tkn) ;
        }
    }
}


int main(){
    int n ;
    cin >> n ;
    for(int i = 1; i <= n; i++)
        scanf("%I64d",&a[i]) ;
    for(int i = 1; i < n ; i++){
        int tmp ;
        ll cost ;
        scanf("%d %I64d", &tmp , &cost) ;

        G[i + 1].pb({tmp , cost}) ;
        G[tmp].pb({i + 1, cost}) ;
    }
    ans = 0;

    dfs(1 , 0 , 0 ) ;
    cout << ans << endl;
    return 0;
}
