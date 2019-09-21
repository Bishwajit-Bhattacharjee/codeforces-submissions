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

ll gcd(ll a,ll b)
{
    if(a == 0 or b == 0) return a + b;
    return __gcd(a,b);
}

int x1,x2,x3,x4,x5,x6;
int y_1,y2,y3,y4,y5,y6;

ll dp[N];
ll cum[N] ;
int dig_cnt(ll n)
{
    int cnt = 0;
    while(n){
        n /= 10;
        cnt++;
    }
    return cnt;
}

void solve(ll num, ll pos)
{
    assert(pos >= 0);
    vector < int > dig;

    while(num){
        dig.push_back(num%10);
        num /= 10;
    }
    reverse(dig.begin(), dig.end());
    cout << dig[pos-1] << '\n';
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    
    // cin >> x1 >> y_1 >> x2 >> y2;
    // cin >> x3 >> y3 >> x4 >> y4;
    // cin >> x5 >> y5 >> x6 >> y6;
    // vector <int > v;
    // for(int x = x1; x <= x2; x++){
    //     v.clear();
    //     if(x3 <= x and x4 >= x){
    //         v.push_back(y3);
    //         v.push_back(y4);
    //     }
    //     if(x5 <= x and x6 >= x){
    //         v.push_back(y5);
    //         v.push_back(y6);
    //     }
    //     if(v.empty()){
    //         cout << "yes\n";
    //         return 0;
    //     }        
    //     if(v[0] > y_1){
    //         cout << "yes\n";
    //         return 0;
    //     }        
    //     if(v.back() < y2){
    //         cout << "yes\n";
    //         return 0;
    //     }        
    //     if(v.size() == 4 and v[2] < v[3] and y_1 <= v[2] + 1 and y2 >= v[2] + 1){
    //         cout << "yes\n";
    //         return 0;
    //     }
    // }
    // cout << "NO\n";


    dp[0] = 0;

    for(int i = 1; i < N; i++)
        dp[i] = dp[i-1] + dig_cnt(i), cum[i] = cum[i-1] + dp[i];
    
    int q;
    cin >> q;
    while(q--){
        ll k;
        cin >> k;

        int id = lower_bound(cum,cum + N, k) - cum;
        id--;
        k -= cum[id];

        for(int i = 1; ; i++){
            int c = dig_cnt(i);
            if(c < k){
                k -= c;
            }
            else {
                solve(i,k);
                break;
            }
        }
    }

    return 0;   
}