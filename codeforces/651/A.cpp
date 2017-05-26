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

#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1000 + 10;
int const mod = 1e9 + 7;
using namespace std;

ll dp[MX][MX];

ll f(int i, int j)
{
    if(i <= 0 || j <= 0)
        return 0;
    ll &ret = dp[i][j] ;
    if(ret != -1)
        return ret;
    ret = max(1 + f(i + 1,j - 2), max(1 + f(i -2, j - 2), 1 + f(i -2, j +1 )));
    return ret;
}


int main()
{
    memset(dp, -1,sizeof dp);
    int a1, a2;
    cin >> a1 >> a2;
    if(a1 == 1 && a2 == 1)
        cout << "0";
    else
    cout << f(a1,a2);

    return 0;
}
