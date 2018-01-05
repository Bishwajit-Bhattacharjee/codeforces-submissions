#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up1 = 1e3 + 10;
int const up =  100000; //(int) //sqrt(1000000000*2 + 1);
using namespace std;
vector < int > plist;
int mark[1000000];
void prime ()
{
    ll i , j ;
    ll n = up;
    ll limit = sqrt(n *1.0) + 2;
    mark[1] = 1;
    for(int i = 4; i <= n; i += 2)
        mark[i] = 1;
    plist.pb(2);
    for( i = 3; i <= n; i++)
    {
        if(!mark[i])
        {
            plist.pb(i);
            if(i <= limit)
            {
                for(j = i*i; j <= n; j += i * 2)
                {
                    mark[j] = 1;
                }
            }
        }
    }
}

int main()
{
    int mark1[1010] ;
    int n ;
    cin >> n ;

    prime() ;

    for(int ix = 1; ix <= n; ix++){
        ll num ;
        scanf("%lld",&num) ;
        memset(mark1, 0 ,sizeof mark1) ;
        if(num == 2 ) {
            cout << "1/6" << endl;
            continue ;
        }

        ll mn = max(num-500, 2LL ) ;
        ll mx = min(num + 500, (ll)1e10) ;
    //    set < ll > s;
        for(auto pr : plist)
        {
            ll st = mn / pr ;

            for(ll i = st ; i * pr <= mx ; i++){
                if(i * pr >= mn && i * pr != pr ) {

                  //  cout << pr * i << endl;
             //       s.insert(i*pr) ;
                    mark1[i*pr - mn] = 1 ;
                }
            }
        }

      //  cout << mark1[11-mn] << endl;
        if(!mark1[num+1-mn]) {
            ll p = num + 1 ;
            printf("%lld/%lld\n",p-2,2*p );
            continue;
        }
        else {
            ll bame , dane ;
            for(ll i = num ; ; i--){
                if(!mark1[i-mn]) {
                    bame = i ;
                    break;

                }
            }
            for(ll i = num+1; ; i++) {
                if(!mark1[i-mn])
                {
                    dane = i ; break;
                }
            }
          //  cout << bame <<  ' ' << dane << endl;
            ll opor = (bame - 2)*dane + 2*(num - bame + 1) ;
            ll niche = 2 * bame * dane ;
            ll tmp = __gcd(opor, niche) ;

            cout << opor / tmp << '/' << niche / tmp << endl;
        }

    }

    return 0;

}
