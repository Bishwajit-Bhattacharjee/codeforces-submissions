
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

    ll ara[MX];


bool isSquare(ll num)
{
    ll tmp = sqrt(num) ;

    return tmp * tmp == num ;
}
int main()
{
   //s;
    FAST ;
    int ans = 1000;

    ll num;
    cin >> num;


    int cnt = 0;
    int tmp = num;
    vector < int > lst;

    while(tmp)
    {
       // cnt++;
        lst.pb(tmp % 10 ) ;

        tmp /= 10;

    }

    //all(lst)) ;

    cnt = lst.size() ;

    for(int i = 0; i < (1 << cnt) ; i++)
    {
        ll tmp = 0;
        bool f = 0;
        for(int x = cnt-1 ; x >= 0 ; x--)
        {
            if(i & (1 << x) )
            {
                if(!f && lst[x] == 0) {
                    break;
                }
                else
                {
                    f = 1;
                    tmp = tmp * 10 + lst[x] ;
                }

            }

        }
       // cout << tmp << endl;
        if(tmp && isSquare(tmp))
            ans = min(ans ,cnt -  __builtin_popcount(i) ) ;

    }
    if(ans  != 1000)
        cout << ans << endl;
    else
        cout << "-1" << endl;
    return 0;
}
