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

PLL base = {103,101};
PLL M = {1000000021, 1e9 + 9 };

ll val(char ch )
{
	return (ch - '0' + 1);
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string s;
	cin >> s;
	//cout << (int)('0')  << endl;

	vector < int > dp(s.size() + 2) ;
	dp[0] = 1;
	ll sum = 0;
	PLL FH = {val(s[0]),val(s[0])};
	PLL RH = {val(s[0]),val(s[0])} ;
	PLL power = base;
	ll ans = 1;

	for(int i = 1; i < s.size(); i++)
	{
		FH = (FH  + power * val(s[i]) ) % M ;
		power = (power * base) % M ;
		RH = (RH * base + val(s[i])) % M ;
		if(FH == RH)
			dp[i] = dp[(i/2 - (i%2 == 0))] + 1;
		ans += dp[i] ;
	}
	cout << ans << endl;
	return 0;

}