#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    
    while(t--){
        ll n;
        cin >> n;
        vector < ll > factor;
        
        for(ll i = 2; i * i <= n; i++){
            if(n % i == 0){
                factor.push_back(i);

                if(i * i != n){
                    factor.push_back(n/i);
                }                
            }
        }
        bool f = 0;
        
        for(auto x : factor){
            for(auto y : factor){
                if(n % x == 0 and n / x % y == 0){
                    ll tmp = n / x / y;
                    if(!f and tmp != 1 and tmp != x and x != y and y != tmp){
                        f = 1;
                        cout << "YES\n";
                        cout << x << " " << y << " " << n / x / y << '\n';
                    }
                }
            }
        }
        if(!f){
            cout << "NO\n";
        }
    }

    return 0;
}