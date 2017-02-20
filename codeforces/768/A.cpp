
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end


int main()
{
    vi v;
    int n, t;
    cin >> n;

    for(int i = 0 ; i < n; i++)
        {  scanf("%d",&t);v.pb(t);}
    if(n == 1)
    {
        cout << 0 ;
        return 0;
    }
    sort(v.begin(), v.end()) ;
    int cnt = 0;
    int a= v[0], b = v[n-1];
    for(int i = 0; i < n; i++)
    {
        if(v[i] > a && v[i] < b)
            cnt++;
    }
    cout << cnt ;
    return 0;
}
