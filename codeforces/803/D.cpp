#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()
#include <chrono>

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1 % MOD;
    ll x = bigmod(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2)
        x = (x * a) % MOD;
    return x;
}

int const N = 3e5 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string str;
int k;
vector < string > token;


ll val(int mid)
{
    ll cnt = 1;
    ll so_far = 0;
    for(int i = 0; i < token.size(); )
    {
        if(token[i].size() + ( (i + 1) != token.size()) > mid )
        {
            return k + 1;
        }
        if(so_far + token[i].size() + ( (i + 1) != token.size()) <=  mid)
        {
            so_far += token[i].size() + ( (i + 1) != token.size());
            i++;
        }
        else {
            so_far = 0;
            cnt++;
        }
        //cout <<
    }
    return cnt;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> k;
    cin.ignore();
    getline(cin,str);
    //cout << str << endl;
    for(auto &ch : str)
    {
        if(ch == '-') ch = ' ';
    }
    stringstream stream(str);
    string tmp;
    ll l = -1;
    while(getline(stream,tmp,' '))
    {
        token.push_back(tmp);
        l = max(l,(ll)tmp.size());

    }
    if(token.size() == 1) {
        //cout << "here" << endl;
        return cout << token[0].size() << '\n', 0;
    }

    ll lo = l , hi = str.size();
    ll ans = hi + 1;


    //cout << " val-2 : " << val(2) << endl;
    //cout << lo << " " << hi << endl;
    while(lo <= hi)
    {
        ll mid = (lo + hi) / 2;
        //cout << lo << " " << hi << " " << mid << " val " << val(mid) << endl;
        if(val(mid) <= k) {
            ans = min(ans, mid);
            hi = mid - 1;
        }
        else
            lo = mid + 1;
    }
    cout << ans << endl;

    return 0;
}
