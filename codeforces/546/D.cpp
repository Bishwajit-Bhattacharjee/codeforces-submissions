#include <bits/stdc++.h>
#define PII pair < int , int >
#define  PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX = 5  * 1e6 + 8  ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;
int a[MX];
ll cnt[MX];
vi p;


int div(int n){
    
    for(int i = 0; i < p.size(); i++){
        if(n % p[i] == 0)
            return 1 + a[n / p[i]];
    }
    
}


void solve(){
    for(int i = 1; i <= MX; i++)
        a[i] = 1;
   //int i;
   //a[1] = 1;
   //a[2] = 1;
   p.pb(2);
   for(int i = 4; i <= MX; i+= 2)
        a[i] = 0;
    int root = sqrt(MX * 1.0) + 2;
    for(int i = 3 ; i <= MX ;i++){
        //if()
        if(a[i]){
                p.pb(i);
            if(i <= root)
            for(int j = i * i ; j <= MX; j += 2 * i){
                a[j] = 0;
                
            }
        }
    }
   // for(int i = root + 3; i <= MX; i++)
     //   if(a[i] == 0)
       // p.pb(i);
    for(int i = 2; i <= MX; i++){
        if(!a[i]){
            a[i] = div(i);
        }
    }
    cnt[1] = 0;
    for(int i = 2; i <= MX; i++){
        cnt[i] = cnt[i-1] +(ll)a[i];
    }
    
}
int main()
{
    solve();
    int a,t, b;
    cin >> t;
    for(int i = 1; i <= t;i++){
        scanf("%d %d", &a,&b);
       // printf("%I64d\n", cnt[i]);
        printf("%I64d\n", cnt[a] - cnt[b]);
    }
    return 0;
}
