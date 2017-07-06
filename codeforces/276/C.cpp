//HK HK HK HK HK 108 times


#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second

int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 * 1e5 + 10;
int const mod = 10000007;
using namespace std;
inline long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
template <class T> inline T modinverse(T a,T M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************
 int num_idx[MX];
 int a[MX];



 //******************************************************************************************************************************
 int main()
{
    int n, q;
    while(cin >> n >> q){
      memset(num_idx, 0 , sizeof num_idx);
      for(int i =0 ; i < n; i++)
        scanf("%d", &a[i]);
      sort(a, a + n, greater < int > ());
      for(int i = 0; i < q; i++){
        int l , r;
        scanf("%d  %d", &l , &r);
        num_idx[l]++ ;
        num_idx[r + 1]--;
      }
        num_idx[0] = 0;
      for(int i = 1 ; i <= n; i++){
         num_idx[i] += num_idx[i-1];
      }
      sort(num_idx + 1 , num_idx + n + 1, greater < int > () );
      ll ans = 0LL;
      for(int i = 0 ; i < n; i++){
        ans +=  (ll)a[i] * num_idx[i+1];
      }
      cout << ' ' << ans << endl;
    }

   return 0;
}



