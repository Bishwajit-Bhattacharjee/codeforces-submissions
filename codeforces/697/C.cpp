#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

map < ll, ll > m;
void update(ll u, ll v, ll w)
{
    //m[u]+= w, m[v]+= w;
    while(u != v)
    {
        if(u > v)
            swap(u , v);
      //  v /= 2;
        m[v] += w;
        v /= 2;
    }
  //  m[v] -= w;
}
ll  solv(ll u, ll v)
{
    ll ans = 0LL;
    //ans += (m[v] + m[u]);
    while(u != v)
    {
        if(u > v)
            swap(u, v);
      //  v /= 2;
       ans +=  m[v];
        v /= 2;
    }
   // ans -= m[v];
    return ans;
}

int main( )
{
   int q;
   cin >> q;
   int t ;
   for(int i =0 ; i < q; i++){
    scanf("%d", &t);
    ll u, v, w;
    if(t == 1){
        cin >> v >> u >> w;
         update(v, u, w);
    }
    else {
       // scanf("%I64d%I64d", &v, &u);
       cin >> v >> u;
           //cin >> v >> u >> w;
     //   scanf("%I64d%I64d%I64d",&v, &u, &w);
        printf("%I64d\n", solv(v, u));
    }

  //  cout << "sdsfsdjf" << m[4] << endl;
 //  return 0;
   }
   return 0;
}
