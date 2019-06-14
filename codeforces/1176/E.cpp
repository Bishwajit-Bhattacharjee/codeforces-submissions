#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;

PLL operator+(PLL a,PLL b){ return {a.first + b.first, a.second + b.second}; }
PLL operator-(PLL a,PLL b){ return {a.first - b.first, a.second - b.second}; }
PLL operator*(PLL a,PLL b){ return {a.first * b.first, a.second * b.second}; }
PLL operator/(PLL a,PLL b){ return {a.first / b.first, a.second / b.second}; }
PLL operator%(PLL a,PLL b){ return {( b.first + a.first) % b.first, (b.second + a.second) % b.second}; }
PLL operator%(PLL a,ll b){ return {a.first % b, a.second % b} ;}
PLL operator+(PLL a,ll b){ return {a.first + b, a.second + b} ;}
PLL operator-(PLL a,ll b){ return {a.first - b, a.second - b} ;}
PLL operator*(PLL a,ll b){ return {a.first * b, a.second * b} ;}

ostream& operator<<(ostream &out,PLL a)
{
    out << "( " << a.first << ", " << a.second << " )" ;
    return out;
}

/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
int const N = 2e5 + 100;
int dist[N];
bool vis[N];
vector < int > g[N] ;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int n,m;
        cin >> n >> m;
        for(int i = 0; i <= n; i++)
            g[i].clear(), vis[i] = 0, dist[i] = 0;

        for(int i = 0; i < m; i++){
            int a,b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        //    deg[a]++, deg[b]++;
        }
        int lc[2] = {0,0};


        queue < int > q;
        dist[1] = 0;
        q.push(1);
        vis[1] = 1;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto v : g[top]){
                if(!vis[v]){
                    vis[v] = 1;
                    q.push(v);
                    dist[v] = dist[top] + 1;
                }
            }
        }

        for(int i =1; i <= n; i++){
            lc[dist[i] & 1]++;
        }
        assert(lc[0] + lc[1] == n);

        if(lc[0] < lc[1]){
            cout << lc[0] << '\n';
            for(int i = 1; i <= n ;i++)
                if(dist[i] % 2 == 0)
                    cout << i << " " ;

        }
        else {
            cout << lc[1] << '\n';
            for(int i = 1; i <= n;i++)
                if(dist[i] & 1)
                    cout << i << " " ;
        }
        cout << '\n';

    }
    return 0;
}
