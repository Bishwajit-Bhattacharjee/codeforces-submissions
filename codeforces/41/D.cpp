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

int ara[110][110] ;
int n,m,k ;
int dp[110][110][20] ;

int DP(int x, int y, int mod)
{

    if(x >= n or y < 0  or y >= m )
        return INT_MIN;
    if(x == 0)
    {
        int tmp = mod + ara[x][y] ;
        while(tmp >= (k+1))
            tmp -= k+1;

        if(!tmp)
            return ara[x][y] ;
        else
            return INT_MIN;
    }

    int &ret = dp[x][y][mod] ;
    if(ret != -1)
        return ret;

    ret = 0;
    int tm = mod + ara[x][y] ;
    while(tm >= (k+1))
        tm -= k+1;

    ret = ara[x][y] + max(DP(x-1,y-1, tm), DP(x-1,y+1, tm)) ;
    //cout << ret << endl;
    return ret;

}

void print(int x,int y, int mod)
{
    if(x == 0)
    {
        return ;
    }
    int val = DP(x,y,mod) ;

//    ret = 0;
    int tm = mod + ara[x][y] ;
    while(tm >= (k+1))
        tm -= k+1;
    int c1 = DP(x-1,y-1, tm) ;
    int c2 = DP(x-1,y+1, tm) ;
    if(val == c1 + ara[x][y])
    {
        cout <<"L" ;
        print(x-1,y-1,tm);
    }
    else
    {
        cout <<"R" ;
        print(x-1,y+1,tm);

    }

   // return ret = ara[x][y] + max(DP(x-1,y-1, tm), DP(x-1,y+1, tm)) ;
}
int main()
{
    ios_base::sync_with_stdio(false) ;
    cin.tie(0) ;
    cout.tie(0) ;
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r",stdin);
#endif

    cin >> n >> m >> k;

    string s[110] ;
    for(int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        s[i] = str ;
        for(int j =0 ; j < s[i].size(); j++)
        {
            ara[i][j] = s[i][j] - '0';
          //  cout << ara[i][j] << " " ;
        }
        //cout << endl;
    }
    memset(dp,-1,sizeof dp);

    int ans = INT_MIN;
    int col = -1;
    for(int i = 0;i < m;i++)
    {
        int can = DP(n-1,i,0) ;
       // cout << ara[n-1][i] << endl;
        if(can > ans)
        {
            //cout << ans << endl;
            ans = can;
            col = i ;
        }
    }

    if(ans < 0 )
    {
        cout << "-1" << endl;
        return 0;
    }
    cout << ans << endl;
    cout << col + 1 << endl;
    print(n-1,col,0);
    //cout << ans << " " << col << endl;
    return 0;
}
