#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector < int > v(n);
        for(int i = 0; i < n; i++){
            cin >> v[i] ;
        }
        int ans = 0;
        int mn = 2e9 ;
        for(int i = n - 1; i >= 0; i--){
            if(v[i] > mn){
                ans++;
            }
            mn = min(mn,v[i]);
        }
        cout << ans << '\n';
    }
    
    return 0;
}