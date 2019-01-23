#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    
    int l1, r1, l2, r2;
    
    while(q--)
    {
        cin >> l1 >> r1 >> l2 >> r2 ;
        cout << l1 << " " << ((l2 == l1)? r2 : l2) << '\n';
    }
    return 0;
}