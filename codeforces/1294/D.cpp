#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q,x;
    cin >> q >> x;
    vector < int > mod(x,0);
    int mex = 0;

    while(q--){
        int y;
        cin >> y;
        y %= x;
        mod[y]++;
        
        while(mod[mex%x] > 0){
            mod[mex%x]--;
            mex++;
        }
        //cout << "ascho?\n";
        cout << mex << '\n';
    }
    return 0;
}