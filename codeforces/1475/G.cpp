#include<bits/stdc++.h>
using namespace std;

int const N = 2'000'10;
vector<int> divi[N];

int main(){

    for (int i = 1; i < N; i++) {
        for (int j = i; j < N; j += i) 
            divi[j].push_back(i);
    }

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n+1), dp(N, 0);

        for (int i = 1; i <= n; i++) cin >> v[i];

        sort(v.begin()+1, v.end());
        

        for (int i = 1; i <= n; i++){
            int val = v[i];
            int tmp = 0;
            for (auto x : divi[val]){
                tmp = max(tmp, dp[x]);
            }
            dp[val] = 1 + tmp;
        }

        cout << n - *max_element(dp.begin(), dp.end()) << "\n";
    }
    return 0;
}