#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    ll a, b ;
    cin >> a >> b;
    ll ans = 1LL;
    ll mn = min(a, b);
    for(int i = 1 ;i <= mn; i++) ans *= i;
    cout << ans << endl;
    
    return 0;
}