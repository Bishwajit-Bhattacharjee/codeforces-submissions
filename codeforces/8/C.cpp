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
vector < pair < int , PII >  >  edge  ;
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

int xs, ys;
vector < PII > v;
int dp[(1<<24) + 5] ;
int dist[30][30] ;

int n ;
int Dist(int i, int j)
{
   return dist[i][n] + dist[j][n] + dist[i][j] ;

}
int DP(int mask)
{
    if(mask == ((1<<n) - 1))
        return 0 ;
    int &ret = dp[mask] ;
    if(ret != -1)
        return ret;
    ret = INT_MAX;
    int first ;
    for(int i = 0; i < n;i++)
    {
        if(!(mask & (1<<i)) )
        {
            first = i ;
            break;
        }
    }
    ret = min(ret,Dist(first, first) + DP(mask ^ (1<<first))) ;

    for(int j = 0 ; j < n; j++)
    {
        if( !(mask & (1 << j )) && first != j )
        {
            int tmp_mask = mask^(1<<j) ;
            tmp_mask ^= (1<<first) ;
            ret = min(ret, Dist(first,j) + DP(tmp_mask)) ;
        }
    }
    return ret ;
}

void print(int mask)
{
    if(mask == ((1 <<n ) - 1))
        return;

    int cur = DP(mask);

    int first ;
    for(int i = 0; i < n;i++)
    {
        if(!(mask & (1<<i)) )
        {
            first = i ;
            break;
        }
    }
    if(cur == Dist(first, first) + DP(mask ^ (1<<first)))
    {
        cout << " " << first+1 << " 0" ;
        print(mask^(1<<first));
        return;
    }
   // ret = min(ret,Dist(first, first) + DP(mask ^ (1<<first))) ;

    for(int j = 0 ; j < n; j++)
    {
        if( !(mask & (1 << j )) && first != j )
        {
            int tmp_mask = mask^(1<<j) ;
            tmp_mask ^= (1<<first) ;
            if( cur == (Dist(first,j) + DP(tmp_mask) ) )
            {
                cout << " " << 1 + first << " " << j + 1 << " 0" ;
                print(tmp_mask) ;
                return ;
            }
        }
    }
   // return ret ;

}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("in.txt","r", stdin) ;
#endif // ONLINE_JUDGE

    cin >> xs >> ys ;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        PII tmp; cin>> tmp.F >> tmp.S ;
        v.pb(tmp) ;
    }
    v.pb({xs,ys}) ;
    memset(dp,-1,sizeof dp) ;

    for(int i =0 ; i < v.size(); i++)
    {
        for(int j = 0 ; j < v.size(); j++)
        {
            int dx = v[i].F - v[j].F ;
            int dy = v[i].S - v[j].S ;
            dist[i][j] = dx*dx + dy*dy;
        }
    }
    cout << DP(0) << endl;

    cout << "0 " ;
    print(0);

    return 0;
}
