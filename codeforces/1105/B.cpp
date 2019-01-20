#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()

//int const N = 1;
int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;//;
vector  < int > g[30];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, k ;

    cin >> n >> k;

    string s;
    cin >> s;

    for(int i = 0; i < s.size(); i++)
    {
        g[s[i]-'a'].pb(i);
    }

    int ans = 0;
    for(int i = 0; i < 26; i++)
    {
        int tmp = 0;
        if(g[i].size())
        {
            int last = -1;
            int cnt = 0;

            for(int j = 0; j < g[i].size(); j++)
            {
                if(last == -1 or g[i][j] - last == 1)
                {
                    cnt++;
                    if(cnt == k)
                    {
                        cnt = 0;
                        tmp++;
                        last = -1;
                    }
                    else
                        last = g[i][j];
                }
                else {

                    cnt = 1;
                    last = g[i][j];
                }
            }
            if(cnt == k)
                tmp++;
        }
        ans = max(ans,tmp);
    }
    cout << ans << endl;
    return 0;
}


