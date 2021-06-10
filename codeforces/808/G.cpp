#include <bits/stdc++.h>
using namespace std;

using ll = long long int;
int const ALPHA = 26;
vector<vector<int>> aut; // aut[i][j] means first i character matched(i = 0 means no character matched yet) and 
                    // given char j, where will the state go?

vector<int> prefix_function(string &s){
    vector<int> pi(s.size(), 0); // for i in [0...n-1] pi[i] is the maximum length 
            //of **proper** prefix that is also suffix of the substring s[0..i]

    pi[0] = 0;
    for (int i = 1; i < s.size(); i++){
        int last = pi[i-1];
        while (last > 0 && s[last] != s[i]) last = pi[last-1];
        pi[i] = last + (s[last] == s[i]);
    }
    return pi;
}


void build_automata(string s){
    vector<int> pi = prefix_function(s);
    s += '#';
    for (int i = 0; i < s.size(); i++){
        for (int c = 0; c < ALPHA; c++){
            if (!i) aut[i][c] = s[i] == c + 'a';
            else if (s[i] == c + 'a') aut[i][c] = i+1;
            else aut[i][c] = aut[pi[i-1]][c];
        }
    }
}
const int M = 1e9 + 7;
vector<vector<ll>> dp;
int n;
string s, t;

ll DP(int l, int state){
    if (l == s.size()) return state == t.size();
    ll &ret = dp[l][state];
    if (ret != -1) return ret;
    ret = (state == t.size());
    if (s[l] != '?') {
        int nxt = aut[state][s[l]-'a'];
        ret += DP(l+1, nxt);
        return ret;
    }
    ll mx = 0;
    for (int c = 0; c < ALPHA; c++){
        int nxt = aut[state][c];
        mx = max(DP(l+1, nxt), mx);
    }
    ret += mx;
    return ret;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    cin >> s >> t;
    aut.assign(t.size()+3, vector<int>(ALPHA));
    dp.assign(s.size()+3, vector<ll>(t.size()+3, -1));
    build_automata(t);

    cout << DP(0,0) << '\n';
    return 0; 
}