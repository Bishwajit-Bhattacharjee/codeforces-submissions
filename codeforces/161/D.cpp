#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int const N = 5e4 + 10;
int n, k;
vector<vector<int>> g;
ll dp[N][505];
ll ans = 0;

void dfs(int u, int p){

    dp[u][1] = 1;

    for (auto v : g[u]){
       if (v == p) continue;
       dfs(v, u);

       for (int here = 0; here < k; here++){
           ans += dp[u][k-here] * dp[v][here]; 
       } 

       for (int here = 0; here < k; here++){
           dp[u][here + 1] += dp[v][here];
       }
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> n >> k;
    k++;
    g.assign(n+1, vector<int>());
    
    for (int i = 0; i < n - 1; i++){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs(1, -1);

    cout << ans << endl;

    return 0;
}