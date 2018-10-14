/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int const INF = 10;


int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    
    ll t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (1LL <<(int)__builtin_popcount(n)) << '\n';
        
    }

    return 0;
}