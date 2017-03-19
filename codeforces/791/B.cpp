#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 150010 ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

vector < int > adj[MX];
int vis[MX] = {0};
ll node = 0;
ll dfs(int s){
    
    vis[s] = 1;

    for(int i = 0; i < adj[s].size(); i++){
        if(vis[adj[s][i]] == 0){
            dfs(adj[s][i]);
        }

    }
    node++;
    return node;
}

int main(){
    ll n, m;
    int  a, b;
    cin >> n >> m;
    for(int i = 0;i  < m; i++) {
            scanf("%d %d",&a, &b);
            adj[a].pb(b);
            adj[b].pb(a);
    }
    ll sum = 0;
    for(int i = 1;i <= n; i++){
        node = 0;
       if(vis[i] == 0){
          node = dfs(i);
          sum += (long long)(node*(node-1))/2;

       }
    }
       // printf("%d\n", sum);
    if(sum == m){
        puts("YES");
    }
    else
        puts("NO");


    return 0;
}
