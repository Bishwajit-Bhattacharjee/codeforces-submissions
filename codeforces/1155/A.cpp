#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 20;
int const SZ = (1<<N) + 10;

ll a[SZ],b[SZ],c[SZ];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int  n;
    string s;
    cin >> n >> s;

    for(int i = 0; i + 1 < s.size(); i++)
    {
        if(s[i] > s[i+1] )
        {
            cout << "YES" << endl;
            cout << i + 1 << " " << i + 2 << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
