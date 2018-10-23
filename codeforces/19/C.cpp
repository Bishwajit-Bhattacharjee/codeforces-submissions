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

PLL base = {102559,102563} ;
PLL M = {1e9 + 7, 1e9 + 9 };

vector <int> normal(vector <int >& v)
{
	map < int, int > mp;
	vector < int > temp(v.size()) ;
	int id = 1;
	for(int i = 0; i < v.size(); i++)
	{
		int x = v[i] ;
		if(!mp.count(x)){
			mp[x] = id++;
		}
		temp[i] = mp[x];
	}
	return temp;
}
int const MX = 1e5 + 10;

vector < int > dan[MX] ;
vector < PLL > power(MX+1) ;

void hashing(vector < int > &ara,vector < PLL > &h)
{
	power[0] = {1,1};

	for(int i = 1; i < MX; i++)
	{
		power[i] = (power[i-1] * base) % M ;
	}

	h[0] = {ara[0],ara[0]};

	for(int i = 1; i < ara.size(); i++)
	{
		h[i] = (h[i-1] * base + ara[i]) % M ;
	}

}

bool valid(int l,int r, vector < PLL > &h)
{
	int len = r - l ;
	
	//cout << l << " "<< r << " " <<  r + len - 1 << endl;

	if(r + len - 1 >= h.size())
		return 0;

	//cout << len << endl;
	PLL c1 = h[l + len - 1] ;
	//c1 = (c1 - h[l - 1]*p[len] ) % M ) + M ) % M;
	if(l){
		c1 = ( (c1 - h[l-1]*power[len]) % M  + M) % M;
	}
	PLL c2 = h[r + len - 1] ;
	if(r){
		c2 = ( ( c2 - h[r-1]*power[len]) % M + M) % M ;
	}
	//cout << c1 << c2 ;

	return c1 == c2 ;

}
int main()
{
	#ifndef ONLINE_JUDGE
		freopen("in.txt","r",stdin);
	#endif

	int n;
	cin >> n;
	vector < int > v(n) ;
	for(int i = 0; i < n; i++)
		cin >> v[i];
	vector < int > nv = normal(v) ;


	vector < PLL > hash(nv.size());


	hashing(nv,hash);

	int rgt = -1;

	for(int i = 0; i < nv.size(); i++)
	{
		int now = nv[i] ;
		for(int x = (int)dan[now].size() - 1; x >= 0; x--){
			if(dan[now][x] > rgt and valid(dan[now][x],i,hash)){
				rgt = i - 1 ;
			}
		}
		dan[nv[i]].pb(i);
	}

	cout << (n - rgt - 1)  << '\n';

	for(int i = rgt + 1; i < n; i++)
	{
		cout << v[i] << " " ;
	}
	cout << '\n';


	return 0;
}