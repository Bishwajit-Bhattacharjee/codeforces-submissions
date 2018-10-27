#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define F first
#define S second
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

PLL base = {37,41};

PLL M = {1000000021, 1e9 + 9 };
int const MX = 2e6 + 10;

PLL P[MX];
PLL h[MX] ;

map < PLL, int > mp;

PLL Hash(string &s)
{
    PLL hh = {0,0};

    for(int i = 0; i < s.size(); i++)
    {
        hh = (hh * base + (s[i] - 'a' + 1)) % M ;
    }
    //cout << hh << endl;

    return hh ;
}

PLL sub(int l,int r)
{
    return ( (h[r] - (h[l-1]*P[r-l+1])) % M + M ) % M ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    P[0] = {1,1};

    for(int i = 1; i < MX; i++)
        P[i] = (P[i-1] * base) % M;


    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    s += s;


    h[0] = {0,0} ;

    for(int i = 0; i < s.size(); i++){
        h[i+1] = (h[i] * base +  (ll)(s[i] - 'a' + 1))% M ;
    }

    int g;
    cin >> g;

    for(int i = 0; i < g; i++)
    {

        string s;
        cin >> s;
        //cout << Hash(s) << endl;

        mp[Hash(s)] = i+1;
    }
    vector < int > ans;
    vector < bool > vis(g+1,0);
    bool f = 0;

    for(int i = 1; i <= k && !f ; i++){
        ans.clear();
        int cnt = 0;
        for(int j = i,cnt = 1; j + k - 1 <= s.size() and cnt <= n; j += k, cnt++){
            PLL tempHash = sub(j,j+k-1);
            //cout << tempHash << endl;

            if(mp.count(tempHash) and !vis[mp[tempHash]]){
                ans.pb(mp[tempHash]);
                vis[mp[tempHash]] = 1;
            }

        }
        if(ans.size() == n){
            f = 1;
            break;
        }
        for(int i =0 ; i < ans.size(); i++)
            vis[ans[i]] = 0;
    }

    if(!f){
        return cout << "NO", 0 ;
    }
    cout << "YES" << '\n';

    for(auto x: ans)
        cout << x << " " ;
    cout << endl;

    return 0;
}
