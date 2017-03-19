#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back

ll const inf =  1LL << 59 ;
int  const MX  = 1e5 + 10 ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

vector < int > adj[MX];
int cat[MX];
int vis[MX] = {0};
int ans = 0;
int m;
void dfs(int s, int c){

    vis[s] = 1;
    if(c > m)
        return ;
    if(adj[s].size() == 1  && s != 1){
        if(c <= m)
            ans++;
            //printf(" ans %d ", ans);
        return;
    }
    for(int i = 0; i < adj[s].size(); i++){
        if(vis[adj[s][i]] == 0){
           if(cat[adj[s][i]] == 0)
                dfs(adj[s][i], 0);
           else
             dfs(adj[s][i], c + 1);
        }
    }

    return ;
}

int main(){
    int   n;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
        scanf("%d", &cat[i]);
        int mx , mn;

    for(int i = 1; i < n; i++){
        scanf("%d %d", &mn, &mx);

        adj[mn].pb(mx);
        adj[mx].pb(mn);
    }
    int x = cat[1];
    dfs(1, x);
    cout << ans << endl;


    return 0;
}
