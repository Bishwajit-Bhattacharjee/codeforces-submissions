#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main(){
    ll n, k, ans ;
    cin >> n >> k;
    ll t1 , t2;
    t1 = (n/2) /(1LL + k);
    cout << t1 << ' ' << t1 * k << ' ' << n - (t1 + t1 * k);
    return 0;
    
}