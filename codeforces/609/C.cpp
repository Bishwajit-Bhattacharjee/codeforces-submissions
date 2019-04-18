#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;
int main() {
    ios::sync_with_stdio(false) ;cin.tie(0);
    
    int n;
    cin >> n;
    vector < int > a(n), b(n) ;
    ll sum = 0;
    for(int i =0 ;i < n; i++)
        cin >> a[i] , sum += a[i] ;
    
    ll mod = sum % n;
    ll each = sum / n;
    
    for(int i =0;i < n; i++)
    {
        b[i] = each + ((i + 1) <= mod);
    }
    
    sort(b.begin(),b.end());
    sort(a.begin(),a.end());
    
    ll ans = 0;
    
    for(int i =0;i < n; i++)
        ans += abs(a[i] - b[i]) ;
    cout << ans / 2 << endl;
    
    
    return 0;
}