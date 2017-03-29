#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 2 *1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

vector < int > adj[MX];
//vector < int > le[MX];
int vis[MX] = {0};
//int level[MX];
//int color[MX];

int ans = 0;
void dfs(int i){
    vis[i] = 1;
    for(int j  = 0 ; j < adj[i].size();j++){
        if(vis[adj[i][j]] == 0)
            dfs(adj[i][j]);
    }
 }
int main(){
    int n, m, a, b;
    cin >> n ;
    for(int i = 1;i  <= n; i++) {
            scanf("%d",&a);
        //    if(i == 1) m = b;
            adj[a].pb(i);
            adj[i].pb(a);
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(vis[i] == 0){
            dfs(i);
            cnt++;
        }
    }
    cout << cnt ;
    return 0;
}
