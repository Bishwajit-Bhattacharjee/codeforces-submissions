#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
#define MX 5 * 1000000 + 7
#define ll long long int 
ll f[MX + 5];
bool flg[MX];
int main()
{
    ll t, l , r;
    cin >> t >> l >> r;
    for(int i = 2 ;i <= MX; i++)f[i] = 1e18 + 10; 
  //  f[2] = 1;
  f[1] = 0 ;
    for(int i = 1 ; i <= MX ; i++){ // number of  grp 
        // if(!flg[i]) f[i] = min(f[i],((i-1)* i * 1LL) / 2 );
        for(int j = 2 *  i,k = 2;  j  <= MX ; j += i, k++ ){
           //flg[j]  = 1;
            f[j] = min(f[j],1LL * i * k * (k-1) /2  + f[i] );
        }
      
       
    }
    //cout << f[(int)1e5] << endl;
  //  for(int i = 1; i < 30 ; i++)cout <<i << ' '<< f[i] << endl; 
    ll tmp = 1LL, ans = 0LL;
    
    for(int i = 0 ; i <= (int)(r - l) ; i++){
//     cout << ans << endl;
        ans += ((tmp % mod) * (f[i + l] % mod )) % mod;
        ans %= mod;
        tmp =(tmp % mod) * t ;  tmp %= mod;
    }
    cout << ans << endl;
    return 0;
}