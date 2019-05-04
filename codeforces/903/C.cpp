#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 10;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    map < int , int > mp;
    int ans = 0;
    for(int i = 1; i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        mp[tmp]++;
        ans = max(ans,mp[tmp]);
    }
    cout << ans << endl;
    return 0;
}
