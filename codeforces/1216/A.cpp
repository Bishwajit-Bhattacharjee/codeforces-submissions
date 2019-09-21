#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair <ll,ll> PLL;

ll const MOD = 1e9 + 7;

ll bigmod(ll a,ll b)
{
    if(b == 0) return 1;

    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    
    if(b & 1) {
        x = (x * a) % MOD;
    }
    return x;
}
int const N = 2e5 + 100;
int const INF = 1e9;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    string out = "";
    for(int i = 0; i < s.size(); i+= 2){
     if(s[i] == s[i+1]){
         out += "ab";
         ans++;
     }else
     {
         /* code */

        out += s[i] ;
        out += s[i+1] ;
     }
     
    }
    cout << ans << endl;
    cout << out << endl;

    return 0;   
}