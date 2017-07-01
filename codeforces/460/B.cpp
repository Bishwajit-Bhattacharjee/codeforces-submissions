#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll power(ll x, ll a){
   ll tmp = 1LL;
   while(a--) tmp *= x ;
  return tmp;
}
ll sum(ll num)
{
    ll ans = 0;
    while(num){ans +=  num % 10 , num /= 10 ; }
    return ans;
}

int main(){
  ll a, b, c;
  vector < ll  > v;
  cin >> a >> b >> c;
  
  for(ll x = 1; x <= 81; x++){
    //  cout << power(x, a) << ' ' ;
      ll tmp = c + b * power(x, a);
      if(sum(tmp) == x &&tmp < 1000000000 && tmp > 0 ) v.push_back(tmp);
  }
  cout << v.size() << endl;
  
  for(int i =0 ; i < v.size(); i++)
    cout << v[i] << ' ' ;
    return 0;
}