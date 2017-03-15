#include <bits/stdc++.h>
#define PII pair < int , int >
#define  PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 5  * 1e5 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


int main()
{
   map < string , int > m;
   m["Tetrahedron"] = 4, m["Cube"]  = 6, m["Octahedron"] = 8, m["Dodecahedron"] =  12,
   m["Icosahedron"] = 20;
   int n;
    int ans = 0;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++ )
    {
        cin >> s;
        ans += m[s];
    }
    cout << ans ;


    return 0;
}
