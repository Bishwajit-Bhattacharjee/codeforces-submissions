#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < ll,ll > PLL;

int const MX = 1e5 + 10;
int col[MX] ;
vector < int > g[MX] ;

map < int,int > *cnt[MX];
ll ans[MX] ;
ll sub[MX] ;
PLL subMax[MX] ;

int sz(int u,int p)
{
    int ans = 1;
    for(auto v : g[u]) {
        if(v != p)
        {
            ans += sz(v,u);
        }
    }
    return sub[u] = ans;
}

void dfs(int u,int p)
{
    int mx = -1, big = -1;

    for(auto v : g[u]){
        if(v != p ){
            dfs(v,u);
            if(sub[v] > mx)
                mx = sub[v], big = v;
        }
    }
    PLL bigInfo ;

    if(big != -1)
        cnt[u] = cnt[big] , bigInfo = subMax[big] ;
    else
        cnt[u] = new map < int , int >(), bigInfo = {0,0};

    //mx = (big != -1)?(subMax[big]): 1;
    ll nodeAns = 0;
    nodeAns = bigInfo.second;
    mx = bigInfo.first;

    (*cnt[u])[col[u]]++;

    if(mx < (*cnt[u])[col[u]])
    {
        mx =(*cnt[u])[col[u]];
        nodeAns = col[u] ;
    }
    else if(mx == (*cnt[u])[col[u]]){
        nodeAns += col[u] ;
    }
    for(auto v : g[u]){
        if(v != p and v != big)
        {
            for(auto x : *cnt[v]){

                (*cnt[u])[x.first] += x.second;
                if((*cnt[u])[x.first] > mx){
                    mx = (*cnt[u])[x.first];
                    nodeAns = x.first;
                }
                else if((*cnt[u])[x.first] == mx){
                    nodeAns += x.first;
                }
            }
        }
    }

    bigInfo = {mx,nodeAns} ;
    ans[u] = nodeAns;
    subMax[u] = bigInfo;

}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n ;


    for(int i = 1; i <= n; i++)
        cin >> col[i] ;

    for(int i = 1; i <= n - 1; i++)
    {
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sz(1,-1);

    dfs(1,-1);

    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ' ;
    cout << endl;

    return 0;
}
