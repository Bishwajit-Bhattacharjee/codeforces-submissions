#include <bits/stdc++.h>
using namespace std;

map < int , int > primeCnt;

void factorize(long long num)
{
    long long st = 2;
    long long root = sqrt(num) + 10 ;
    for(st = 2 ; st <= root ; st++){
        while(num % st == 0) {
            num /= st ;
            primeCnt[st]++;
        }
        root = sqrt(num) + 10 ;
    }
    if(num > 1 )
        primeCnt[num]++;
}
const int mod = 1e9 + 7;
long long com[510*30][510] ;

long long DP(int n, int r )
{
    if(n < r ) return 0 ;
    if( r == 0 ) return 1 ;
    r = min(r, n - r ) ;
    long long &ret = com[n][r] ;

    if(ret != -1 ) return ret ;

    return ret = (DP(n-1,r-1) + DP(n-1, r )) % mod ;

}

int main()
{
    int n ;
    cin >> n ;
    for(int i = 1; i <= n; i++){
        int tmp ;
        cin >> tmp ;
        factorize(tmp) ;
    }
    memset(com, -1,sizeof com) ;

    long long ans = 1LL;

    for(auto p : primeCnt)
    {

        long long tmp = p.first ;
       // cout << DP(3,2) << endl;
        ans = (ans * DP(n - 1 + p.second, n-1)) % mod ;
    }
    cout << ans << endl;

}
