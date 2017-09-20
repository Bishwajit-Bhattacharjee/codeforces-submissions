#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 2 * 1e5 + 10 ;
vector < int > G[MX];

int key[MX];
int a[MX] ;
/*
void bs(int num ) {
    if(num > key[0])
    {
        G[0].pb(key[0]) ;
        key[0] = num ;
        return ;
    }
    int lo = 1 , hi = MX - 1 ;
    while(lo < hi ) {
        int mid = ( lo + hi + 1 ) / 2 ;
        if()
    }
}
  */
int main()
{
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++)
        scanf("%d", &a[i]) ;

    //memset(key, -1, sizeof key) ;
    for(int i = MX - 1 ; i >= 0  ; i-- )
        key[i] = -1 ;
    key[MX - 1] = a[0] ;
    for(int i = 1 ;i < n  ; i++) {
        int idx ;
        auto it = upper_bound(key, key + MX , a[i] );
        idx = it - key ;
        idx-- ;
    //    cout << "idx " << idx << endl ;
       // cout << a[i] << ' ' << (int)(it - key) << endl ;
       if(key[idx] > 0 ) {
               G[idx].pb(key[idx]) ;

        }
        key[idx] = a[i] ;

     /*   if(it == key + n ) {
             idx = MX - 1 ;
             G[idx].pb(key[0]) ;
             key[0] = a[i] ;
        }
        else {



        }
       */
    }
    for(int i = 0 ; i < MX ; i++) {
        if(key[i] > 0 )
            G[i].pb(key[i]) ;
    }

    for(int i = MX-1; i >= 0 ; i--) {
        if(G[i].size()){
            for(auto j : G[i])
                printf("%d " , j ) ;
            printf("\n") ;
        }

    }


    return 0;
}
