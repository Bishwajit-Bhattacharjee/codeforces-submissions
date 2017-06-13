// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
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
/*
void dfs(int move, int last, int diff){
   if(move == m){
      flag = 1;
    return ;
   }
   chk[move][last][diff + 10] = true;
   if(move % 2 == 0){
     for(int i = 0; i< w.size(); i++){
        if(diff + w[i] > 0  && last != w[i] && !chk[move][last][diff + 10])
           {
            dfs(move + 1, w[i], diff + w[i]);
           }
   }
   else {
    for(int i = 0 ; i < w.size(); i++){
        if(diff - w[i] < 0 && last != w[i] && !chk[move][last][diff + 10])
            dfs(move + 1, w[i], diff - w[i]);
    }
   }
}
vector < ll > a, b , c;
vector < ll > ca((int)1e5 + 10 ), cc((int)1e5 + 10);

int main()
{

    int t, n;
    cin >> t;
    while(t--)
    {
      int p , q, r;
      cin >> p >> q >> r;
      a.clear(); b.clear();c.clear();

      for(int i = 0,  t; i < p ; i++){scanf("%lld", &t); a.pb(t);
      for(int i = 0, t ; i < q; i++){scanf("%lld", &t); b.pb(t);
      for(int i = 0 , t; i < r; i++)scanf("%lld", &t), c.pb(t);
      sort(a.begin(), a.end());
      sort(b.begin() , b.end()) ;
      sort(c.begin(), c.end());
      ca[0] = a[0], cc[0] = c[0];
      for(int i = 1; i < p ; i++) {
        ca[i] = ca[i-1] + a[i]; ca[i] %= mod; }
      for(int i = 1; i < r; i++)  {
        cc[i] = cc[i-1] + c[i]; cc[i] %= mod; }

        ll ans = 0LL;
        for(int i = 0; i < q; i++){
            ll num_a =  upper_bound(a.begin(), a.end(), b[i]) - a.begin();
            ll num_c = upper_bound(c.begin(), c.end(), b[i]) - c.begin();
            ll idx_a = num_a - 1;
            ll idx_c = num_c - 1;
            ans += (((b[i] * b[i]) % mod) * ((num_a * num_c) % mod)) % mod;
            ans %= mod;
            ans += (((b[i] % mod) *((idx_a >= 0 ?ca[idx_a] : 0) % mod)) * num_c)  % mod;
            ans %= mod;
            ans += ((b[i] * ((idx_c >= 0)?cc[idx_c] : 0 ) % mod) * num_a) % mod;
            ans %= mod;


        }
       ll num_a =  upper_bound(a.begin(), a.end(), b[0]) - a.begin();
       ll num_c =  upper_bound(c.begin(), c.end(), b[0]) - c.begin();
        ll tmp = 0LL;
        for(int i = 0; i < num_a; i++){

            tmp +=  a[i] *(num_c == 0 ? 0 : cc[num_c - 1]);
            tmp %= mod;
        }
        ans += tmp ; ans %= mod;
        for(int i = 1; i < q; i++){
        ll t1 =  upper_bound(a.begin(), a.end(), b[i]) - a.begin();
        ll t2 =  upper_bound(c.begin(), c.end(), b[i]) - c.begin();
         for(int i = (int)num_a ; i < (int)t1; i++)
            tmp +=  ( a[i] * (t2 == 0 ? 0 : cc[t2-1]) ) % mod;
         for(int i = (int)num_c; i < (int)t2 ; i++)
            tmp += (c[i] * (num_a == 0 ? 0 :  ca[num_a - 1])) % mod;
         ans += tmp ;
         ans %= mod;
         num_a = t1, num_c = t2;

        }
      cout << ans << endl;
    }
    return 0;
}
*/
int main(){
  int n;
  cin >> n;
  //int a[101010];
  vi a(n);
  for(int i = 0; i < n; i++)
    scanf("%d", &a[i]);
   vector < int > b = a;
   sort(b.begin(), b.end()) ;
   int cnt = 0;
   for(int i = 0; i  < n; i++){
    if(a[i] != b[i])
        cnt++;
   }
   if(cnt <= 2)
    cout << "YES";
   else
    cout << "NO";
   return 0;
}
