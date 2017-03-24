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
int color[MX];
int ans = 0;
int a;
void dfs(int i, int x, int y){
    //int a;
    color[i] = x;
    ans = max(ans ,(int) adj[i].size() + 1);
   if(i == 1){
    for(int j = 0, a = 1; j < adj[i].size(); j++){
            int v = adj[i][j];

        if(vis[v] == 0){
            vis[v] = 1;
           // a = 1;
            while(x == a || y == a){
                a++;
            }
            dfs(v, a, x);
            a++;
        }
    }
   }
   
   else {    
       for(int j = 0, a= 1; j < adj[i].size(); j++){
         // = 1;
         
        int v =  adj[i][j];
        if(vis[v] == 0){
          // ans = max(ans , adj[i].size() + 1);
          vis[v] = 1;
        //  a = 1;
           while(a == x || a == y){
            a++;
           }
           dfs(v, a, x);
           a++;
        }
    }

   }
}
int main(){
    int n, m, c, b;
    cin >> n ;
    for(int i = 1;i  < n; i++) {
            scanf("%d %d",&c, &b);
        //    if(i == 1) m = b;
            adj[c].pb(b);
            adj[b].pb(c);
    }
    vis[1] = 1;
    dfs(1, 1, 0);
    cout << ans << endl;
    for(int i = 1; i <= n; i++){
        printf("%d ", color[i]);
    }
    return 0;
}