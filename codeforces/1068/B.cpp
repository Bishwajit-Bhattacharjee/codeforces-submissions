/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define S second
#define F first
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int const MX = 1e5 + 10;


int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    
    ll b;
    cin >> b;
    set < ll > s;

    for(ll i = 1; i * i <= b; i++)
    {
        if(b % i != 0)
            continue;

        s.insert(i);
        s.insert(b/i);
    }
    cout << s.size() << endl;
    
    return 0;
}