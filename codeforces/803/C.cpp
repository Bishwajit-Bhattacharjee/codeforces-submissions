#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0) ;
    long long n,k;
    cin >> n >> k;
    set < long long > s;

    for(long long i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
            s.insert(i), s.insert(n/i);

    }
    if(k > 10000000)
    {
        cout << "-1" << endl;
        return 0;
    }

    long long ans = -1;
    for(auto x: s)
    {
        //cout << x << endl;
        if(k*(k+1)/2 > n/x)
            continue;

        ans = max(ans,x) ;
    }
   // cout << ans << endl;
    if(ans == -1)
        cout << ans << endl;
    else
    {
       // cout << ans << endl;
        n /= ans;

        for(int i = 1; i < k;i++)
            cout << i*ans << " " ;
        k--;
        long long tmp = n - k*(k+1) / 2;
        cout << ans*(tmp) << endl;
    }
    return 0;
}
