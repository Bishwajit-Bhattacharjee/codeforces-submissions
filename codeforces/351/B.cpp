#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector< int > ara(n);
    for(int i =0; i < n; i++)
        cin >> ara[i] ;
    int inv = 0;

    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
            inv += (ara[i] > ara[j]);
    }
    vector < int > dp(inv+1,0);

    dp[0] = 0, dp[1] = 1;

    for(int i = 2;i <= inv; i++)
        dp[i] = 4 + dp[i-2];

    cout << dp[inv] << endl;
    return 0;
}
