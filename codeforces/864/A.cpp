#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 1e3 + 10 ;
ll const MOD =  1000000007  ;

int main()
{
    int n ;
    //cin >> n ;
    while(cin >> n ){
       //int cnt[110] ;
       map < int , int > m ;
       int a[110] ;
      // memset(cnt , 0 , sizeof cnt) ;
       for(int i =0 ; i < n; i++ ) {
            cin >> a[i] ;
          //  cnt[a[i]]++ ;
            m[a[i]]++ ;
       }
       bool f = 0 ;
       //int tmp = 0;
       if(m.size() == 2) {
            int tmp = 0;
          for(auto i : m) {
             tmp ^= i.S ;
          }
        if(tmp == 0){
            f = 1 ;
        }
       }
       if(f == 1){
          puts("YES") ;
          for(auto i : m ) {
            cout << i. F << ' ' ;

          }
       }
       else {
        puts("NO") ;
       }

    }
    return 0;
}
