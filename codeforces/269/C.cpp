#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5;

struct dat {
   int v, i, c, d;
};

int N, M;
vector<dat> G[MAXN + 10];
int res[MAXN + 10];
int flow[MAXN + 10];

int main() {
   scanf("%d%d", &N, &M);
   for(int i = 1; i <= M; i++) {
      int u, v, c; scanf("%d%d%d", &u, &v, &c);
      G[u].push_back(dat{v,i,c,0});
      G[v].push_back(dat{u,i,c,1});
      flow[u] += c; flow[v] += c;
   }
   for(int u = 2; u < N; u++) {
      flow[u] /= 2;
   }
   memset(res, -1, sizeof(res));
   queue<int> q; q.push(1);
   while(!q.empty()) {
      int u = q.front(); q.pop();
      for(auto e : G[u]) {
         if(res[e.i] != -1) continue;
         res[e.i] = e.d;
         flow[e.v] -= e.c;
         if(e.v < N && flow[e.v] == 0) {
            q.push(e.v);
         }
      }
   }
   for(int i = 1; i <= M; i++) {
      printf("%d\n", res[i]);
   }
}