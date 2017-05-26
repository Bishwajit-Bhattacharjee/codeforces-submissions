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
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;

ll f(ll n){
  ll r = 1LL;
  while(n)
    r*= (n--);
  return r;
}

int cnt[1010];

int main()
{
  //  int a[1010];
    int n, x;
    cin >> n;
    F(i, 0 , n)
    {
        scanf("%d", &x);
        cnt[x]++;

    }

    int ans = 0,t ;
    int mx = *max_element(cnt+1, cnt + 1001);
    for(int j = 1; j <= mx; j++) {

      t = 0;
    for(int i = 1; i < 1001; i++)
    {

        if(cnt[i]>0){
            t++;
            cnt[i]--;
        }

    }
    ans += t-1;
    }
     cout << ans;
    return 0;
}
