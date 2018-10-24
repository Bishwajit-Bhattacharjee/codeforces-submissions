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

ll base = 101;
//PLL M = {1000000021, 1e9 + 9 };
ll M = 1e9 + 21;

int dp[(int)5e6 + 10] ;

ll E[(int)5e6 + 10] ;

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

	E[0] = 1;
	for(int i = 1; i < 5e6 + 6; i++)
		E[i] = (E[i-1] * base ) % M ;

	dp[0] = 1;
	ll sum = 0;
	ll FH = val(s[0]);
	ll RH = FH ; //{val(s[0]),val(s[0])} ;
	ll power;
	ll ans = 1;

	for(int i = 1; i < s.size(); i++)
	{
		power = E[i] ;
		FH = (FH  + power * val(s[i]) ) % M ;
		RH = (RH * base + val(s[i])) % M ;
		if(FH == RH)
			dp[i] = dp[(i/2 - (i%2 == 0))] + 1;
		ans += dp[i] ;
	}
	cout << ans << endl;
	return 0;

}