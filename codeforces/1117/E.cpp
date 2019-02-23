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

struct trip{
    char c1, c2, c3;
    trip(){}
    trip(char x1, char x2, char x3){
        this->c1 = x1;
        this->c2 = x2;
        this->c3 = x3;
    }
    bool operator<(const trip &x)const {
        if(c1 == x.c1){
            if(c2 == x.c2){
                return c3 < x.c3 ;
            }
            return c2 < x.c2;
        }
        return c1 < x.c1;
    }
};

int main()
{
   /*  ios::sync_with_stdio(0);
    cin.tie(0);
 */
    string s;
    cin >> s;
    int cnt = 0;
    map < trip, int > mp;
    map < int, trip > rec;
    bool f = 1;
    for(int i = 0; i < 26 and f ; i++)
    {
        for(int j = 0; j < 26 and f; j++){
            for(int k = 0; k < 26 and f; k++){

                //cnt;
                //cout << (char)('a'+i ),(char)('a'+j),(char)('a'+ k) << endl;
                mp[trip((char)('a' + i), (char)('a' + j), (char)('a' + k))] = cnt;
                rec[cnt] = trip((char)('a' + i), (char)('a' + j), (char)('a' + k));
                cnt++;
                if (cnt == s.size()) f = 0;
            }
        }
    }

    string q[3], a[3] ;

    for(int i = 0; i < s.size(); i++)
    {
        q[0] += rec[i].c1;
        q[1] += rec[i].c2;
        q[2] += rec[i].c3;
    }

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < q[i].size(); j++)
            assert(q[i][j] >= 'a' and q[i][j] <= 'z') ;
    }
    for(int i = 0; i < 3;i++)
    {
        cout << "? " << q[i] << endl;

        cin >> a[i] ;
    }
    vector < char > ans(s.size(), ' ') ;
    set < int > st;
    for(int i = 0; i < s.size(); i++)
    {
        int ind = mp[trip(a[0][i], a[1][i],a[2][i])] ;
        st.insert(ind);
        ans[ind] = s[i] ;
    }
    assert(st.size() == s.size());
    string tmp = "";
    for (auto x : ans)
    {
        assert( x == ' ' or (x >= 'a' and x <= 'z' ));
        tmp += x;
        //cout << x;
    }
    cout << "! " << tmp << endl;// ;


    //cout << endl;

    return 0;
}
