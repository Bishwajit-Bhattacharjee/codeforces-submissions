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

ll base = 10;
PLL M = {1000000021, 1e9 + 9 };

int const MX = 1e6 + 10;

string s;

vector < PLL > h(MX+1) ;
vector < PLL > P(MX+1) ;
ll val(char ch)
{
	return (ch - '0');
}

PLL hashi(int i,int j)
{
	int len = j - i + 1;
	return ( (h[j+1] - h[i]*P[len]) % M + M ) % M ;
}
bool check(PII a,PII b, PII c)
{
	int sa = a.S - a.F + 1;
	int sb = b.S - b.F + 1;
	int sc = c.S - c.F + 1;

	if((s[a.F] == '0' and sa != 1) or (s[b.F] == '0' and sb != 1) or (s[c.F] == '0' and sc != 1))
		return 0;
	if((a.S - a.F + 1) <= 0 or (b.S - b.F + 1) <= 0 or (c.S - c.F + 1) <= 0 )
		return 0;
	if(a.S < a.F or b.S < b.F or c.S < c.F)
		return 0;
	PLL h1 = hashi(a.F ,a.S) ;
	PLL h2 = hashi(b.F, b.S) ;
	PLL h3 = hashi(c.F,c.S) ;
	return ((h1 + h2 ) % M == h3 );
}
PLL valid(int len3)
{
	int i3 = s.size() - len3, j3 = s.size() - 1;
	int i1 = 0, j1 = len3 - 1;
	int i2 = j1 + 1, j2 = i3 - 1;
	//cout << PLL(i1,j1) <<" " <<  PLL(i2,j2) << " " << PLL(i3,j3) << endl;
	if(check({i1,j1},{i2,j2},{i3,j3})){
		return {i1,j1};
	}
	i1 = 0, j1 = len3 - 2;
	i2 = j1 + 1, j2 = i3 - 1;
	if(check({i1,j1},{i2,j2},{i3,j3})){
		return {i1,j1};
	}

	j2 = i3 - 1, i2 = j2 - len3 + 1;
	i1 = 0, j1 = i2 - 1;
	if(check({i1,j1},{i2,j2},{i3,j3})){
		return {i1,j1};
	}

	j2 = i3 - 1, i2 = j2 - (len3 - 1) + 1;
	i1 = 0, j1 = i2 - 1;
	//cout << PLL(i1,j1) <<" " <<  PLL(i2,j2) << " " << PLL(i3,j3) << endl;
	if(check({i1,j1},{i2,j2},{i3,j3})){
		return {i1,j1};
	}

	return {-1,-1};

}
int main()
{	
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	cin >> s;
	//cout << s << endl;

	h[0] = {0,0};

	h[1] = {val(s[0]),val(s[0])};

	P[0] = {1,1};

	for(int i = 1; i < MX; i++)
		P[i] = (P[i-1] * base) % M ;

	for(int i = 1; i < s.size(); i++)
		h[i+1] = (h[i] * base + val(s[i]) ) % M ;


	for(int i = (int)s.size() - 1; i >= 0; i--)
	{
		/*if(s[i] == '0')
			continue;*/
		int len3 = (s.size() - i );

		PLL pr = valid(len3);
		//cout << i << " " << len3 << " " << pr << endl;

		if(pr.F != -1){

			cout << s.substr(pr.F,pr.S-pr.F + 1) << '+' << s.substr(pr.S + 1,(i-1-(pr.S+1) +1)) << '=' << s.substr(i,(int)s.size()-1 - i + 1) << endl;
			
			return 0;
		}
	}

	assert(0);

	return 0;
}