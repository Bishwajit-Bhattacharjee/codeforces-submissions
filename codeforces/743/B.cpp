// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define F(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define f first
#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1e5 + 10;
int const mod = 10000007;
using namespace std;

ll log(ll x)
{
    ll ans  =0;
    while(x!= 1){
        x/= 2;
        ans++;
    }
    return ans;
}
ll p2(ll x)
{
    ll ans = 1LL;
    while(x--)
    {
        ans *= 2;
    }
    return ans;
}
ll recurse(ll s , ll e  , ll k)
{
    if((s + e)/2 == k)
        return log(e + 1);
    ll mid = (s + e)/ 2;
    if(k < mid)
    return  recurse(s, mid - 1, k);
    if(k > mid)
        return  recurse(mid + 1 - mid , e -mid , k - mid);

}

int main()
{
    ll n, k;
    cin >> n >> k;
    cout << recurse(1, p2(n) - 1, k);

    return 0;
}

