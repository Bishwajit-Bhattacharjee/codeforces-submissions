/// HK 108 Times
#include <bits/stdc++.h>

using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'

ll x, y, l , r;
ll gcd(ll i ,ll j )
{
	if(i == 0 )
		return j;
	if(i > j ) swap(i,j);

	return gcd(i%j,j);
}
bool valid(ll i , ll j)
{
	return (i * x >= l && i * x <= r and j * x >= l and j * x <= r
		and __gcd(i,j) == 1 ) ;
}
int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout) ;
	while(cin >> l >> r >> x >> y)
	{
		if(y % x != 0)
		{
			cout << "0" << endl;
			return 0 ;
		}
		y /= x;
		ll ans = 0LL;

		for(int i = 1; i*1LL*i <= y; i++)
		{
			if(y % i != 0) continue;
			ll j = y / i ;
			if(valid(i,j))
			{
				ans += 2;
				if(j == i )
					ans--;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
