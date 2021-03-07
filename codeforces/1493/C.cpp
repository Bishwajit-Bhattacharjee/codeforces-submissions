#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
using PLL = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()

int n, k;
//int const N =
vector<int> cnt(30), tot(30);

string s;

void find_ans(int pos, int ch, ll need){
    string ans = "";
    
    for (int i = 0; i < 26; i++){
        tot[i] += (k - tot[i] % k) % k;
    }

    for (int i = 0; i < pos; i++){
        tot[s[i] - 'a']--;
        ans += s[i];
    }
    ans += 'a' + (ch);
    tot[ch]--;

    int left = (n - pos - 1) - need;
    tot[0] += left;


    for (int i = 0; i < 26; i++){
        while(tot[i]) {
            ans += 'a' + i;
            tot[i]--;
        }
    }
    cout << ans << "\n";
}

void solve(){
    cin >> n >> k;
    cin >> s;
    fill(all(tot), 0);

    for (auto ch : s) tot[ch - 'a']++;
    if (n % k != 0){
        cout << "-1\n"; return;
    }
    ll need = 0;
    for (int i = 0; i < 26; i++){
        need += (k - tot[i] % k) % k;
    }
    if (!need){
        cout << s << '\n'; return;
    }

    for (int i = n - 1; i >= 0; i--){
        tot[s[i] - 'a']--;

        for (int ch = s[i] - 'a' + 1; ch < 26; ch++){
            tot[ch]++;

            need = 0;
            for (int c = 0; c < 26; c++){
                need += (k - tot[c] % k) % k;
            }
            if (need <= n - i - 1 and (n - i - 1 - need) % k == 0){
                find_ans(i, ch, need);
                return;
            }
            tot[ch]--;
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
