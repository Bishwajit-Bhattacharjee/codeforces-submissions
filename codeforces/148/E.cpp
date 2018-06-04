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

int n,m;
vector < int > ara[110] ;

int dp1[110][110];
int sum[110][110];//]
int nitecai ;
int pre(int n,int nibo)
{
    int &ret = dp1[n][nibo] ;
//    int bame = 0;
    if(ret != -1)
        return ret;
    ret = 0 ;
    for(int bame = 0; bame <= min((int)ara[n].size(), nibo); bame++)
    {
        int bametotal = (bame ==0 )? 0:sum[n][bame-1] ;
        int dane = nibo - bame ;
        int dind = ara[n].size() - dane -1 ;
        int danetotal = sum[n][(int)ara[n].size() - 1] - ((dind < 0)?0:sum[n][dind] );//]
        ret = max(ret, bametotal + danetotal) ;
    }
    return ret;
}

int dp[110][110*110] ;

int DP(int asikoi,int bakikoto)
{
    if(asikoi == n)
    {
        if(bakikoto > 0 )
            return INT_MIN;
        return 0;
    }
    int &ret = dp[asikoi][bakikoto] ;
    if(ret != -1)
        return ret;
    ret = 0 ;
    for(int nibokoyta = 0;nibokoyta <= min((int)ara[asikoi].size(), bakikoto);nibokoyta++)
    {
        ret = max(ret, pre(asikoi,nibokoyta)+ DP(asikoi+1,bakikoto-nibokoyta) ) ;
    }
    return ret;

}
int main()
{


//#ifndef ONLINE_JUDGE
//        freopen("in.txt", "r",stdin);
//#endif
//    ios_base::sync_with_stdio(false) ;
//    cin.tie(0) ;
    memset(dp,-1,sizeof dp);
    memset(dp1,-1,sizeof dp1);

    cin >> n >> m;
    //cout << n << m << endl;
    for(int i = 0 ; i < n; i++)
    {
        int N ;
        cin >> N ;
       // cout << N << endl;
        //ara[i].resize(N);
        for(int j = 0;j < N; j++)
        {
            int tmp;
            cin >> tmp ;
            ara[i].push_back(tmp) ;
            sum[i][j] = ( (j)?sum[i][j-1] : 0 )+ tmp;
        }
        //assert(ara[i].size() == N) ;
    }
    //cout << pre(0,3) ;
   cout << DP(0,m) << endl;
    return 0;
}
