#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
int const ALPHA = 26;
string s,t;
int const N = 1e5 + 10;
int aut[N][ALPHA]; // aut[i][j] -> first i character matched, where
                    // to go now given input j.
int pi[N] ;
vector< vector<ll> > dp;
void KMP(string &s){
    pi[0] = -1;
    for(int i = 1; i < s.size(); i++){
        int now = pi[i-1];
        while(now != -1 and s[now+1] != s[i]) now = pi[now];
        if(s[now + 1] == s[i]) pi[i] = now + 1;
        else pi[i] = -1;
    }

    for(int i = 0; i <= s.size(); i++){
        for(int c = 0; c < ALPHA; c++){
            if(s[i] == ('a'+c)) aut[i][c] = i+1;
            else if(!i) aut[i][c] = 0;
            else aut[i][c] = aut[pi[i-1]+1][c] ;
        }
    }
}
ll DP(int pos, int state){
    assert(state != t.size());
    if(pos == s.size()) return 0;
    ll &ret = dp[pos][state];
    if(ret != -1) return ret;
    ret = 0;
    if(s[pos] != '?'){
        int nxt = aut[state][s[pos]-'a'];
        if(nxt == t.size()) {
            ret = 1 + DP(pos+1, pi[nxt-1]+1);
        }
        else ret = DP(pos+1, nxt);
        return ret;
    }
    for(int ch = 0; ch < ALPHA; ch++){
        int nxt = aut[state][ch];
        if(nxt == t.size()){
            ret = max(ret,1 + DP(pos+1, pi[nxt-1] + 1));
        }
        else ret = max(ret, DP(pos+1, nxt));
    }
    return ret;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> s >> t;
    KMP(t);
    dp.assign(s.size() + 2, vector<ll>(t.size()+2, -1));
    cout << DP(0,0) << '\n';
    return 0;
}