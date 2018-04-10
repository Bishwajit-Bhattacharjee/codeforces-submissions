
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
    int a , b, n;

    cin >> n >> a >> b;

    int sum = a + b;

    string s ;
    s = '*' ;

    string tmp;
    cin >> tmp;

    s += tmp;

    int last = -1;

    for(int i = 0; i < s.size(); i++)
    {

        if(s[i] == '*')
        {
            last = -1;

        }
        else if(s[i] == '.')
        {
            if(last == -1)
            {
                if(a > b && (a || b)) a--, last = 1;
                else if(b) b--, last = 2;
                else
                    last = -1;

            }
            else if(last == 1)
            {
                if(b) {
                    b--;
                    last = 2;
                }
                else {
                    last = -1;
                }
            }
            else
            {
                if(a) {
                    a--;
                    last = 1;
                }
                else
                    last = -1;
            }
        }
    }

    cout << sum - (a + b) << endl;

    return 0;
}
