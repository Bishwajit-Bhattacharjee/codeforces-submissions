#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a,b;
        cin >> a >> b;
        vector<int> mv;
        for(int i = 0; i < n; i++){
            if(a[i] != b[i] ) mv.push_back(i+1), mv.push_back(1), mv.push_back(i+1);
        }
        cout << mv.size() << " ";
        for(auto x : mv) cout << x << " ";
        cout << '\n';
    }
}