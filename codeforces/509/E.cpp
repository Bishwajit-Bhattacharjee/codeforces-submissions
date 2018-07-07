#include <bits/stdc++.h>
using namespace std;

bool isVowel(char ch )
{
    return
    ch == 'A' or
    ch == 'E' or
    ch == 'I' or
    ch == 'O' or
    ch == 'U' or
    ch == 'Y' ;

}
int const MX = 5e5 + 100;
long long dp[MX] ;
long long cum[MX] ;

long long sub(int i, int j)
{
    return cum[j] - cum[i-1];
}
int main()
{
    string s;
    cin >> s;
    int n = s.size() ;
    cum[1] = isVowel(s[0]) ;//'
    for(int i = 2; i <= s.size(); i++)
    {
        cum[i] = cum[i-1] + isVowel(s[i-1]) ;
    }
    dp[1] = sub(1, s.size()) ;
    for(int i = 2; 2 * i <= s.size(); i++)
    {
        dp[i] = dp[i-1] + sub(i,(int)s.size() - i+1) ;
    }
    dp[n] = sub(1,s.size()) ;
    for(int i = n - 1; i * 2 > s.size(); i--)
    {
        dp[i] = dp[i+1] + sub(n-i+1,i) ;
    }
    double ans = 0.0;
    for(int i = 1; i <= n; i++)
    {
        ans += 1.0*dp[i] / (n-i+1) ;
    }
    printf("%.15f\n",ans) ;
    return 0;
}
