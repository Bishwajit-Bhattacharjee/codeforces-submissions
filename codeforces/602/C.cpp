// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1000 + 10;
int const mod = 1e9 + 7;
using namespace std;

int a[401][401];
vector < int > adj[410];
int dist[410];

void bfs(int s)
{
  queue <int > q;
  dist[s] = 0;
  q.push(s);
  while(!q.empty())
  {
      int u = q.front();
      q.pop();
      for(int i = 0; i< adj[u].size(); i++){
        int v = adj[u][i];
        if(dist[v] == -1){
            dist[v] = dist[u] + 1;
            q.push(v);
        }
      }
    }


}
int main()
{
  //  int a[1010];
   int n, m;
   cin >> n >> m;
   int u, v;
   memset(dist, -1, sizeof dist);
   memset(a, 0, sizeof a);
   for(int  i  =0  ; i < m; i++)
   {
       scanf("%d %d", &u, &v);
       a[v][u] = a[u][v] = 1;
   }
   if(!a[1][n]){
     for(int i = 1;  i <= n; i++){
    for(int j = 1; j  <= n; j++) {
        if(a[i][j])
            adj[i].pb(j);

      }
    }
   }
   else {
         for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(!a[i][j]){
                    adj[i].pb(j);
                }
            }
         }
   }
   bfs(1);
   cout << dist[n] << endl;





    return 0;
}
