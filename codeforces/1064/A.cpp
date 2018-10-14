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
    int ara[4];

    for(int i = 0; i < 3; i++)
        cin >> ara[i];
    sort(ara,ara+3);

    cout << max(0,ara[2] + 1 -(ara[0]+ara[1])) << endl;

    return 0;
}