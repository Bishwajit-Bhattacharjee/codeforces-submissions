#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =   1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e5 + 7;
using namespace std;

int main()
{
    int a1[10]={0}, a2[10]={0}, a3[10]={0};
    int n, t;
    cin >> n;
    for(int i = 1 ; i <= n;i++)
    {
        scanf("%d", &t);
        a1[t]++;
    }
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &t);
        a2[t]++;
    }
    for(int i = 1; i <= 5; i++)
    {
        a3[i] = a1[i]  + a2[i];
        if(a3[i] % 2 == 1)
        {
            puts("-1");
            return 0;
        }
        a3[i] /= 2;
    }

    int cnt1 = 0, cnt2 = 0;
    for(int i = 1; i <= 5; i++)
    {
        if(a1[i] > a3[i])
            cnt1 += (a1[i] - a3[i]);
        if(a2[i] > a3[i])
             cnt2 += (a2[i] - a3[i]);
    }
    cout << max(cnt1, cnt2);
    return 0;
}
