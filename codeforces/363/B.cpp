#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int  const inf = 2 *  1e9  ;
int  const MX = 5 * 1e5 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;

int main()
{
    int n,k, tmp;
    cin >> n >> k;
    int a[MX];
    a[0] = 0;
    for(int i = 1; i <= n ; i++){
        scanf("%d", &tmp);
        a[i] = a[i-1] + tmp;
    }
    int ans = inf;
    int id = 0;
    for(int i = 1; i <= n; i++)
    {

        if(i+k - 1 <= n)
        {
            if((a[i+k-1] - a[i-1]) < ans){
                id = i;
                ans = a[i+k-1] - a[i-1];
            }
        }
       // printf("%d ", ans);
    }
    cout << id  << endl;
	return 0;
}
