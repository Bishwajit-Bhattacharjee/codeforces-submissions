#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
#define mp make_pair
#define F first
#define S second
int dp[100][5] ;

int a[100];
int n ;


int DP(int i , bool who)
{
    if(i == n - 1) {
       return a[i] ;
    }
    int &ret = dp[i][who] ;
    if(ret != -1)
        return ret ;
    if(who){
        ret = min( DP(i + 1 , 0 )  , a[i] + DP(i + 1 , 1 ) );
    }
    else {
        ret = max(DP(i + 1 , 1) + a[i] , DP( i + 1, 0 )) ;

    }
    return ret ;

}
int main()
{
    int n ;
    cin >> n ;
    memset(dp , -1, sizeof dp) ;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] ;
        sum += a[i] ;
    }
    int bob = DP(0 , 0) ;
    cout << sum - bob << ' ' <<  bob << endl;
    return 0;
}
