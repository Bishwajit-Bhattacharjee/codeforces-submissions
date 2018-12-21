#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;
int bit[2][N];

vector < int > g[N];
int st[N],en[N],parity[N] ;
int C;

void dfs(int nd, int pr,int mod)
{
    st[nd] = ++C;
    parity[nd] = mod;

    for(auto nxt : g[nd])
    {
        if(nxt != pr)
            dfs(nxt,nd, mod ^ 1);
    }
    en[nd] = C;
}
void update(int id,int pos,int val)
{
    for( ; pos < N ; pos += (pos & -pos)) bit[id][pos] += val;
}
int Q(int id,int pos)
{
    int sum = 0; for( ; pos > 0 ; pos -= (pos & -pos)) sum += bit[id][pos];
    return sum;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector < int > a(n+1);

    for(int i = 1; i <= n; i++)
        cin >> a[i] ;

    for(int i = 1; i < n; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b); g[b].push_back(a);
    }
    dfs(1,-1,0);

    while(m--)
    {
        int t;
        cin >> t;
        if(t == 1)
        {
            int x,val;
            cin >> x >> val;
            update(parity[x],st[x],val);
            update(parity[x],en[x]+1,-val);
            update(parity[x]^1,st[x],-val);
            update(parity[x]^1,en[x] + 1,val);
        }
        else {
            int x;
            cin >> x;
            cout << a[x] + Q(parity[x],st[x]) << '\n';
        }

    }
    return 0;
}
