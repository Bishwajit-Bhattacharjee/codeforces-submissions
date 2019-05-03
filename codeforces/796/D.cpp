#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 3e5 + 10;
vector < int > g[N] ;
typedef pair < int,int > PII;
map < PII, int > id;
set < int > ans;
int sid[N] ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n, k , d;
    cin >> n >> k >> d;

    set < int > s;

    for(int i = 0; i < k; i++)
    {
        int x; cin >> x ; s.insert(x);
    }
    for(int i =1 ; i <= n - 1; i++)
    {
        int a,b; cin >> a >> b ; g[a].push_back(b) ;
        g[b].push_back(a) ;
        if(a < b) swap(a,b);
        id[{a,b}] = i;
    }

    vector < int > dist(n+2), vis(n+2,0);
    fill(dist.begin(), dist.end(), 0);
    queue < int > q;
    for(auto x : s){
        //dist[x] = 0;
        sid[x] = x;
        q.push(x);
        vis[x] = 1;
    }

    while(!q.empty()){
        int top = q.front();
        q.pop();
        for(auto x : g[top]) {
            if(vis[x] and sid[x] != sid[top]){

                ans.insert(id[{max(x,top),min(x,top)}]) ;
            }
            if(!vis[x]){
                vis[x] = 1;
                sid[x] = sid[top];
                q.push(x) ;
            }
        }
    }
    cout << ans.size()<< endl;
    for(auto x : ans) cout << x << " ";

    return 0;
}
