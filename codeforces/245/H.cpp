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

int const MX = 5e3 + 10;
string s;
int dp[MX][MX] ;
int dp1[MX][MX];

bool isPalin(int i, int j )
{
    if(i > j )
        return 1;
    int &ret = dp[i][j] ;
    if(ret != -1)
        return ret;

    if(s[i-1] == s[j-1])
        return ret = isPalin(i+1,j-1);
    return ret = 0;

}

int DP(int i, int j)
{
    if(i > j )
        return 0;
    int &ret = dp1[i][j] ;

    if(ret != -1)
        return ret;
    ret = isPalin(i,j) ;

    ret += DP(i,j-1) + DP(i+1,j) - DP(i+1,j-1) ;

    return ret;

}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
#endif

    cin >> s;
   // cout << s << endl;
    memset(dp, -1,sizeof dp) ;
    memset(dp1,-1,sizeof dp1);
    int q;
    cin >> q;

    while(q--)
    {
        int a, b;
        cin >> a >> b;
     //   cout << a << b << endl;
        cout << DP(a,b) << endl;
    }

    return 0;
}
