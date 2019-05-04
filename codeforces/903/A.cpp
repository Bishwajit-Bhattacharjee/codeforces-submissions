#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 1e5 + 10;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        int t;
        cin >> t;
        bool f = 0;
        for(int a = 0; a <= t; a++){
            for(int b = 0; b <= t; b++){
                if(!f and a * 3 + b * 7 == t) {
                    cout << "YES" << endl;
                    f = 1;
                }
            }
        }
        if(!f) {
            cout << "NO" << endl;
        }
    }
    return 0;
}
