/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
//#define DEBUG(x) cout <<" #(x) <<
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'
int const MX = 2e5 + 10;


ll bigmod(ll base, ll pow, ll mod)
{
        if(!pow)
                return 1 ;
        ll lat = bigmod(base, pow/ 2, mod);
        lat = (lat * lat ) % mod;

        if(pow & 1)
                lat = (lat * base) % mod;
        return lat;

}


int main()
{
   //s;
        ll UMOD = 1e9 + 9 ;

        ll a, b,n, k ;
        cin >> n >> a >> b >> k;

        string s;
        cin >> s ;

        ll ans = 0;

        ll round = (n + 1) / k ;

        ll q = (b * bigmod(a,UMOD - 2,UMOD) ) % UMOD;
        q = bigmod(q, k, UMOD) ;

        //cout << q << endl;

        ll geoTerm = 1;

        if(q == 1)
        {
                geoTerm = round;
        }
        else
        {
                geoTerm = (bigmod(q ,round , UMOD)  - 1  + UMOD ) % UMOD ;
                //geoterm = ge
                ll temp = bigmod((q - 1 + UMOD) % UMOD , UMOD-2, UMOD) ;

                geoTerm *= temp;
                geoTerm %= UMOD;
                //cout << geoTerm << endl ;

        }

        for(int i =0 ;i < s.size(); i++)
        {
                ll tmp = 1;
                tmp = bigmod(a,n-i, UMOD) * bigmod(b,i,UMOD) ;
                tmp %= UMOD;
                int sign = -1;
                if(s[i] == '+') sign *= -1;
                ll nn = tmp * geoTerm ;
                nn %= UMOD ;
                ans = (ans + sign* nn + UMOD) % UMOD;
        }

        cout<< ans << endl;

        return 0;

}
