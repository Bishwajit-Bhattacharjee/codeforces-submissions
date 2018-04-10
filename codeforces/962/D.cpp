
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


struct dat
{
    ll x, y;

    dat(ll xx, ll  yy)
    {
        x = xx ;
        y = yy;

    }
    bool operator<(const dat rhs) const
    {
        if(x == rhs.x )
            return y > rhs.y ;

        return x > rhs.x ;

    }
};

priority_queue < dat > pq;

int main()
{
   //s;
    FAST ;
    int n;
    cin >> n;

    for(int i = 1; i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        pq.push({tmp, i});

    }

    vector < pair<ll, ll > > ans;


    while(!pq.empty())
    {

        dat u = pq.top();
       // cout << u.x <<  ' ' << u.y << endl;
        pq.pop();
       // cout << u.x <<  ' ' << u.y << endl;
        dat v(-1, -1) ;
        int f = 1;
        if(!pq.empty()){
            v = pq.top();

            if(u.x == v.x )
            {
                pq.pop();

                pq.push(dat(u.x * 2, v.y));
                f = 0;

            }
            else
            {
                f = 2;
                ans.pb({u.y, u.x}) ;
            }
        }
        if(f == 1)
        {
            ans.pb({u.y, u.x});
            if(!pq.empty())
                pq.pop();
        }


    }


    sort(all(ans)) ;

    cout << ans.size() << endl;

    for(int i = 0 ; i < ans.size(); i++)
    {
        cout << ans[i].second << ' ' ;
    }



    return 0;
}
