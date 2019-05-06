#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 10;
int const MOD = 1e9 + 7;
int const root = sqrt(1e5) + 10;
int dp[N][root];
int n;

int solve(int a,int k,vector < int > &v)
{
    if(a > n) return 0;
    return 1 + solve(a+k+v[a],k, v);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    vector < int > v(n+1);
    for(int i = 1; i <= n;i++)
        cin >> v[i] ;
    //for(int i = 0; i < root;i++)
        //dp[n][root] = 0;

    for(int kk = 1; kk < root; kk++)
    {
        for(int val = n; val >= 1; val--)
        {
            dp[val][kk] = 1 + (( (val + v[val] + kk ) > n) ? 0 : dp[val + v[val] + kk][kk] );

        }
    }

    int q;
    cin >> q;
    for(int i = 1; i <= q; i++)
    {
        int a,b;
        cin >> a >> b;
        if(b < root) {
            cout << dp[a][b] << '\n';
        }
        else
            cout << solve(a,b,v) << '\n';
    }
    return 0;
}
