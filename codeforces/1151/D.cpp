#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n ;
    long long int ans = 0;

    vector < int > v(n);

    for(int i = 0; i < n; i++){
        int a,b;
        cin >> a >> b ;
        v[i] = a - b;
        ans += 1LL*(-a);
        ans += 1LL* n * b;
    }
    sort(v.begin(), v.end(), greater < int >());

    for(int i = 0; i < n; i++){
        ans += (1LL*v[i]*(i+1));
    }
    cout << ans << endl;
    return 0;
}
