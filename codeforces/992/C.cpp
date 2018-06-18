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

/*long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}*/

ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % MOD);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % MOD;
    if(pow % 2 == 1)
         x = (x * base) % MOD;
    return x;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout) ;
#endif

	ll x, k ;
	while(cin >> x >> k )
	{
		if(x ==0 ) 
		{
			cout << "0" << endl;
			continue;
		}
		else 
		{
			ll ans = bigmod(2,k+1) ;
			ans = (ans * (x % MOD) ) % MOD;
			ans = (ans - bigmod(2,k) + MOD  + 1 ) % MOD ;
			cout << ans << endl;
		}
	}

	return 0;
}