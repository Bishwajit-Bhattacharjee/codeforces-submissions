#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
#define mp make_pair
#define F first
#define S second


int const MX = 1e3 + 10;

struct dish{
    int lft  ;
    int ndsf ;
    int ndd ;
    int cost ;

};

vector < dish > ara ;
int dp[MX][20] ;


int DP(int x, int idx )
{
    if(x == 0 or idx >= ara.size() )
        return 0 ;
    int &ret = dp[x][idx] ;
    if(ret != -1)
        return ret ;

    ret = INT_MIN ;
    if(idx == 0)
    {
      //  ret = max(ret , DP(x , idx + 1)) ;

        for(int i = 0 ; ( x  - i * ara[0].ndd) >= 0  ; i++)
        ret = max(ret , i * ara[0].cost + DP( x - i *  ara[0].ndd , idx + 1 )) ;
        return ret ;
    }

    for(int i = 0 ;  (ara[idx].lft - i * ara[idx].ndsf) >=0   && (x - i * ara[idx].ndd) >= 0 ; i++){
        ret = max(ret , i * ara[idx].cost + DP(x - i * ara[idx].ndd , idx + 1 )) ;


    }
    return ret ;

}

int main()
{
    int n, m , c0 , d0;
    cin >> n >> m >> c0 >> d0;
    ara.pb({n , 0 , c0 , d0  }) ;
    for(int i = 0; i < m ;i++){
        dish tmp ;
        scanf("%d %d %d %d",&tmp.lft , &tmp.ndsf, &tmp.ndd , &tmp.cost) ;
        ara.pb(tmp) ;

    }
    memset(dp , -1, sizeof dp ) ;

    cout << DP(n ,  0 ) << endl;

    return 0 ;
}
