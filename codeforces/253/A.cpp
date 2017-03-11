#include <bits/stdc++.h>
#define PII pair < int , int >
#define  PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 1e7 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string s;
    int n,m,mn, mx;
    cin >> n >> m;
    mn = min(m ,n);
    n -= mn, m -= mn;
    string s1 ;
    if(n) s1 = "BG";
    if(m || n == m) s1 = "GB";

    for(int i = 1; i <= mn; i++)
          s += s1;
    for(int i = 1; i <= n; i++)
        s += "B";
    for(int i = 1; i <= m;i++)
        s += "G";
    cout << s << endl;

    return 0;
}
