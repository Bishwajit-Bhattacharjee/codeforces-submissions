#include <bits/stdc++.h>
using namespace std;
int const N = 4010;
int dp[N][N][3] ;
vector<int> v,special ;
int n;

int DP(int pos, int tkn, int st){
    if(tkn > n) return 0;
    if(pos == 2*n) return tkn == n;
    int &ret = dp[pos][tkn][st];
    if(ret != -1) return ret;
    ret = 0;
    if(special[pos]){
        ret |= DP(pos+1, tkn+(st == 1), st^1);
        ret |= DP(pos+1, tkn+ (st == 0), st);
    }
    else {
        ret |= DP(pos+1, tkn+(st == 0), st);
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        cin >> n;
        v.resize(2*n), special = vector<int>(2*n,0);
        for(int i = 0 ; i < 2 * n; i++) cin >> v[i] ;
        special[0] = 1;
        int id = 0;
        for (int i = 1; i < 2 * n; i++)
            if (v[i] > v[id])
                special[i] = 1, id = i;

        for(int i = 0; i <= 2*n; i++)
            for(int j = 0; j <= 2*n; j++)
                for(int k = 0; k < 3; k++)
                    dp[i][j][k] = -1;
 
        cout << (DP(1,1,0)?"YES":"NO") << '\n';
    }
}