/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
//#define DEBUG(x) cout <<" #(x) <<
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'


ll bigmod(ll base, ll pow, ll mod = MOD )
{
        if(!pow)
                return 1 ;
        ll lat = bigmod(base, pow/ 2, mod);
        lat = (lat * lat ) % mod;

        if(pow & 1)
                lat = (lat * base) % mod;
        return lat;

}
int const MX = 2200 ;
int dist[MX][MX] ;
bool vis[MX][MX] ;

int dx[] = {0,-1,1,0};
int dy[] = {-1,0,0,1};
int n, m;

bool valid(PII tmp)
{
    return !vis[tmp.F][tmp.S] and
    (tmp.F >= 1 and tmp.F <= n and tmp.S >= 1 and tmp.S <= m ) ;
}
int main()
{
#ifdef ONLINE_JUDGE
    freopen("input.txt","r", stdin) ;
    freopen("output.txt","w", stdout) ;

#endif // ONLINE_JUDgE
    cin >> n >> m;
    int k;
    cin >> k;
    queue <  PII > Q;
    for(int i = 0;i < k; i++)
    {
        PII x;
        cin >> x.F >> x.S ;
        Q.push(x) ;
        vis[x.F][x.S] = 1;
        dist[x.F][x.S] = 0;
    }

    while(!Q.empty())
    {
        PII top = Q.front();
        int d = dist[top.F][top.S] ;
        Q.pop();
        for(int i = 0; i < 4; i++)
        {
            for(int j = 0; j < 4; j++)
            {
                PII tmp = {top.F + dx[i], top.S+ dy[i]} ;
                if(valid(tmp))
                {
                    Q.push(tmp);
                    dist[tmp.F][tmp.S] = d + 1;
                    vis[tmp.F][tmp.S] =  1;
                }
            }
        }
    }

    int mx = -1;
    PII ans = {-1,-1} ;

    for(int i = 1; i <= n;i++)
    {
        for(int j = 1; j <= m ;j++)
        {
            if(dist[i][j] > mx)
            {
                ans = {i,j} ;
                mx = dist[i][j] ;
            }
        }
    }
    cout << ans.F << " " << ans.S << endl;
}
