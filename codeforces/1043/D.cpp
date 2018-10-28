#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int,int > PII;
typedef pair < ull,ll > PLL;
#define F first
#define S second
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

ll base = 15485867;

PLL M = {1000000021, 1e9 + 9 };
int const MX = 1e5 + 10;

PLL h[11][MX] ;
PLL P[MX] ;
int ara[11][MX] ;
int pos[11][MX] ;
int n, m;
PLL sub(int l, int r, int id)
{
    return ((h[id][r] - h[id][l-1]*P[r-l+1])  ) ;
}

int bs(int llen, int lpos,int id, int po)
{

    int lo = 1, hi = min(llen,n - po + 1);
    int ans = 0;
    while(lo <= hi)
    {
        int mid = (lo + hi) / 2;
        PLL h1 = sub(po, po + mid - 1, id);
        PLL h2 = sub(lpos,lpos + mid - 1, id -1 );
        if(h1 == h2){
            ans = max(ans,mid);
            lo = mid + 1;
        }
        else
            hi = mid - 1;
    }
    return ans;
}

ll len(int num)
{
    int val;
    val = n - pos[1][num] + 1;
    //cout << num << " " << pos[1][num] << endl;

    if(m == 1) {
        return val;
    }
    for(int i = 2; i <= m ;i++)
    {
        int whr = pos[i][num] ;

        val = bs(val,pos[i-1][num],i,whr);

    }

    return val ;
}

int main()
{
    ios::sync_with_stdio(false);


    cin >> n >> m;

    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++){
            cin >> ara[i][j] ;
            pos[i][ara[i][j]] = j;
            //cout << pos[i][ara[i][j]] << " " << ara[i][j] << endl;

        }
    }

    ll ans = 0;

    P[0] = {1,1} ;

    for(int i = 1; i < MX; i++)
        P[i] = (P[i-1] * base);


    for(int i = 1; i <= m; i++)
    {
        h[i][0] = {0,0} ;

        for(int j = 1; j <= n; j++)
        {
            h[i][j] = (h[i][j-1] * base + ara[i][j] );
        }
    }

    for(int i = 1; i <= n; i++)
    {
        ll tmp = len(i);
        //cout << tmp << endl;

        ans += tmp;
    }
    cout << ans << endl;
    return 0;
}