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


string s;
int mem[5005][5005] ;

PLL H[5005] ;
PLL power[5005];


PLL subHash(int l,int r)
{
	int len = r - l + 1;

	return ( (H[r+1] - H[l]*power[len]) % M + M) % M ;
}
int dp2[5005][5005];

bool isPalin(int l, int r)
{
	if(l > r ) 
		return 1;

	if(l == r)
		return 1;

	int &ret = dp2[l][r] ;
	if(ret != -1)
		return ret;
	if(s[l] == s[r]){
		return ret = isPalin(l+1,r-1);
	}
	return ret = 0;

}
int DP(int l,int r)
{
	if(l == r)
		return 1;
	if(r - l == 1)
	{
		if(s[r] == s[l])
			return 2;
		return 0;
	}
	if(r - l == 2)
	{
		if(s[r] == s[l])
			return 2;
		return 0;
	}
	int &ret = mem[l][r] ;

	if(ret != -1)
		return ret;

	ret = 0;
	int len = r - l;

	int c1 = DP(l,l+(len - 1)/ 2 ) ;
	int c2 = DP(r-(len -1) / 2,r) ;
	PLL h1 = subHash(l,l+(len - 1)/ 2) ;
	PLL h2 = subHash(r-(len - 1) / 2 , r);
	//cout << h1 << " " << h2 << endl;

	if(h1 == h2  and c1 and c1 == c2 )
		return ret = c1 + 1;
	if(isPalin(l,r))
		return ret = 1;

	return ret;

}

ll val(char ch)
{
	return ch - 'a' + 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	memset(mem,-1,sizeof mem);
	memset(dp2,-1,sizeof dp2);

	cin >> s;

	power[0] = {1,1};

	for(int i = 1; i < 5005; i++)
		power[i] = (power[i-1] * base) % M ;

	H[0] = {0,0};

	for(int i = 0; i < s.size(); i++)
	{
		H[i+1] = (H[i] * base + val(s[i])) % M ;
	}

	vector < ll > dp(s.size() + 2, 0 );

	for(int i = 0; i < s.size(); i++)
	{
		for(int j = i ; j < s.size(); j++)
		{
			int val = DP(i,j);
			//cout << i << " " << j << " "<< val << endl;
			dp[val]++;
		}
	}
	for(int i = s.size() - 1; i > 0; i--)
		dp[i] += dp[i+1] ;

	for(int i = 1; i <= s.size(); i++)
	{
		cout << dp[i] << "\n";
	}

	return 0;
}