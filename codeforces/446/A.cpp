#include <bits/stdc++.h>
using namespace std;
int const MX = 1e5 + 10;
int L[MX], R[MX] ;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n+2);
    for(int i = 1; i <= n; i++)
        cin >> v[i] ;
    L[1] = 1;

    for(int i = 2; i <= n;i++)
    {
        if(v[i-1] < v[i]) L[i] = 1 + L[i-1] ;
        else
            L[i] = 1;
    }
    R[n] = 1;
    for(int i = n - 1; i > 0; i--)
    {
        if(v[i] < v[i+1])
            R[i] = R[i+1] + 1;
        else
            R[i] = 1;
    }
    int ans = (n>= 2)?2 : 1;
    v[0] = INT_MIN;
    v[n+1] = INT_MAX;
    for(int i = 1; i <= n;i++){
        if(v[i-1] + 1 < v[i+1])
            ans = max(ans,1 + L[i-1] + R[i+1]) ;
        ans = max(ans,1 + L[i-1]);
        ans = max(ans,1 + R[i+1]) ;
    }
    cout << ans << endl;
}
