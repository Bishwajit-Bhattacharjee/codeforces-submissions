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
int const mod = 1000000007 ;
using namespace std;
 long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}

// ************************************************************** GLOBAL VARIABLES *******************************************



 //******************************************************************************************************************************


ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}

int main()
{
  int sn[27] = {0} ;
  int tn[27] = {0};
  string s, t ;
  cin >> s >> t;
  int cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] == '?') cnt++;
    else
        sn[s[i] - 'a']++;
  }
  for(int i = 0; i < t.size(); i++){
    tn[t[i] - 'a']++;
  }
  string need ;
          int f = 1;

  while(cnt > 0  && f){
     for(int i = 0 ; i  < 27  && f; i++){
      if(tn[i] > 0 ){
     //  for(int j = 0; j < 27  && f; j++){
         if(sn[i] >= tn[i]){
            sn[i] -= tn[i];
           // DEBUG(cnt);

         }
         else {
            //sn[i] = 0;
            int tmp = (tn[i] - sn[i]) ;
            if(tmp <= cnt ){


             cnt -= tmp ;
              sn[i] = 0;
              for(int l =0 ; l < tmp ; l++){
                need +=(char)'a'+ i ;
              }
            }
            else
                f =  0;
         }

      }
     }



  }
  // cout << need << endl;
  if(!f){
    for(int i =0 ; i < cnt ; i++){
        need += (char)'a';
    }
  }
  for(int i = 0 , j = 0; i < s.size(); i++){
    if(s[i] == '?') printf("%c",need[j++]);
    else
       printf("%c", s[i]);
  }

return 0;

}




