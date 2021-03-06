#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back

ll const inf =  1LL << 59 ;
int  const MX  = 2010 ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

vector < int > adj[MX];
int vis[MX] = {0};
ll node = 0;
int dfs(int s){

    vis[s] = 1;
    int mxdp = 0;
    for(int i = 0; i < adj[s].size(); i++){
        if(vis[adj[s][i]] == 0){
           mxdp = max(mxdp,1 + dfs(adj[s][i]));

        }

    }

    return mxdp;
}

int main(){
    int  n, m;
    int  a, b;
    cin >> n;
    for(int i = 1;i  <= n; i++) {
            scanf("%d", &a);
            if(a < 0) a = 0;
            adj[a].pb(i);

    }
    int ans = -1;
    for(int i = 0; i <= n; i++){
        if(vis[i] == 0)
            ans = max(ans, dfs(i));
    }

    cout << ans << endl;


    return 0;
}
