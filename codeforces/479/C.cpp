#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 2 *1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


//int level[MX];
//int color[MX];


int main(){
    int n, a, b ;
    cin >> n;
    vector < PII > d;
    for(int i = 0; i < n; i++){
       scanf("%d %d", &a , &b);
        d.pb(make_pair(a , b));
    }
    sort(d.begin(), d.end());
    int ans = -1;
    for(int i = 0 ; i < n; i++){
        if(ans <= d[i].second)
            ans = d[i].second;
        else
            ans = d[i].first;
    }
    cout << ans ;

    return 0;
}
