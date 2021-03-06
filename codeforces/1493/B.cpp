#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

map<int,int> mp;
int h, m;
int num(char c1, char c2){
    return (c1-'0')*10 + (c2-'0');
}

int rep(int num){
    int a = num / 10, b = num % 10;
    if (mp[a] == -1 or mp[b] == -1) return -1;
    return mp[a] * 10 + mp[b];
}

int rever(int num){
    int a = num / 10, b = num % 10;
    if (mp[a] == -1 or mp[b] == -1) return -1;
    return mp[b] * 10 + mp[a];
}

bool check(int ch, int cm){
    int rh = rever(ch);
    int rm = rever(cm);
    swap(rh, rm);
    if (rh == -1 or rm == -1) return 0;
    return (rm >= 0 and rm < m) and (rh >= 0 and rh < h);
}


string print(int hh, int mm){
    string s = "";
    s += hh / 10 + '0';
    s += hh % 10 + '0';
    s += ':';
    s += mm / 10 + '0';
    s += mm % 10 + '0';

    return s;
}

void solve(){
    cin >> h >> m;
    string s;
    cin >> s;

    int s_h = num(s[0], s[1]);
    int s_m = num(s[3], s[4]);

    for (int xh = s_h; xh <= s_h; xh++){
        for (int xm = s_m; xm < m; xm++){
            int hh = xh % h, mm = xm % m;
            if (check(xh % h, xm % m)){
                cout << print(hh, mm) << "\n";
                return;
            }
        }
    }

    for (int xh = s_h+1; xh <= h; xh++){
        for (int xm = 0; xm < m; xm++){
            int hh = xh % h, mm = xm % m;
            if (check(xh % h, xm % m)){
                cout << print(hh, mm) << "\n";
                return;
            }
        }
    }
    assert(false);
    //cout << num(s[0], s[1]) << " " << num(s[3], s[4]) << endl;

}
int main(){
    mp[1] = 1, mp[2] = 5, mp[3] = -1, mp[4] = -1, mp[5] = 2, mp[6] = -1;
    mp[7] = -1, mp[8] = 8, mp[9] = -1;
    mp[0] = 0;

    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
