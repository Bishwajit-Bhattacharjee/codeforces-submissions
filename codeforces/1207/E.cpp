#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    long long ans = 0;
    
    vector < int > v1, v2;
    //cout << "! ";
    for(int i = 1; i <= 100 ;i++){
        v1.push_back(i);
    }
    cout << "? " ;

    for(auto x : v1){
        cout <<  x << " ";
    }
    cout << endl;
    
    int x;
    cin >> x;
    int mask = (1<<7) - 1;
    ans = x & (mask << 7);

    for(int i = 1; i <= 100; i++){
        v2.push_back((i<<7));
    }

    cout << "? " ;

    for(auto x : v2) {
        assert(x < ((1<<14)));
        cout << x << " ";
    }
    cout << endl;

    cin >> x;
    ans |= x & (mask);

    cout << "! " << ans << endl;
    return 0;
}