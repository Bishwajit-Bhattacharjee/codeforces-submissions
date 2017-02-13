
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
    ll n;
    int a[array_size];
    cin >> n;
    for(int i = 0; i< n;i++)
        scanf("%d", &a[i]);
    sort(a, a + n);
    ll cntmin = 0 , cntmax = 0;
    int mini = a[0], maxi = a[n-1];
    for(int i = 0; i < n;i++)
    {
        if(a[i] == mini)
            cntmin++;
        else if(a[i] == maxi)
            cntmax++;
    }
    if(cntmin == n)
    {

     cout << 0 <<' '<< (n *(n-1)) / 2<< endl;
     return 0;
    }
    else
    {
        cout << maxi - mini << ' ' << cntmin * cntmax << endl;
    }
    return 0;
}
