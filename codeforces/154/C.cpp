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

PLL base = {15485867,32452843};

PLL M = {1000000021, 1e9 + 9 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n,m;
    cin >> n >> m ;

    vector < PLL > h(n+1,{0,0}),P(n+1);

    P[0] = {1,1};

    for(int i = 1; i <= n; i++)
        P[i] = (P[i-1] * base) % M;


    //cin >> n >> m;
    vector < PII > edge(m);

    for(int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;

        edge[i] = {u,v};
        h[u] = (h[u] + P[v]) % M;
        h[v] = (h[v] + P[u]) % M ;
        //cout << h[u] << h[v] << endl;

    }

    ll ans = 0;

    for(auto x : edge)
    {
        int u = x.first , v = x.second;

        if((h[u] + P[u]) % M == (h[v] + P[v]) % M )
            ans++;
    }

    map < PLL, ll > mp;

    for(int i = 0; i < n; i++)
        mp[h[i]]++;

    for(auto x : mp)
        ans += (x.second *(x.second - 1)) / 2;
    cout << ans << endl;

    return 0;
}

