#include <bits/stdc++.h>
using namespace std;
int const N = 18;
typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    vector < double > prob(n+1),dp(n+1,0);
    double tot = 0;
    for(int i =0 ; i < n; i++) cin >> prob[i] , tot += prob[i] ;
    //double sum = 0;
    dp[0] = 0;

    for(int i = 1; i <= n; i++)
        dp[i] = (dp[i-1] + prob[i-1]) * prob[i] ;
    double sum = 0;

    for(int i = 1; i <= n; i++) sum += dp[i] ;

    cout << fixed << setprecision(9) << sum * 2 + tot << endl;



    return 0;
}
