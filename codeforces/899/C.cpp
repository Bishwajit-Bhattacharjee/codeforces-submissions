#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define F first
#define S second
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)

int main()
{
   // READ;

    FAST ;
    int n ;
    while(cin >> n){
             if(n == 3){
                printf("%d\n%d %d\n",n-3,n-2,n);
                continue;
            }
            printf("%d\n",(1LL*n*(n+1)/2 )&1LL);
            ll tot = 1LL*n*(n+1) /2 ;
            bool f = 1;
            printf("%d ", n / 2 );
            int cnt = 0;ll sum = 0;
            for(int i = n ; i >= 2; i -= 2){
                printf("%d ",(f)?i:i-1);
           //     sum += (f)?i:i-1 ;
                f ^= 1 ;
                cnt++;
            }
            //cout << cnt << endl;
            //cout << tot - sum - sum<< ' ' << sum << endl;
//            cout << endl << cnt << ' ' << 1LL*n*(n+1) /2 - sum << endl;
//            cout << endl;
    }
    return 0;
}
