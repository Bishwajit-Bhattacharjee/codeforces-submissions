

/// HK 108 Times
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds;
using namespace __gnu_cxx;
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
#define ll long long
#define MOD 1000000007
#define endl '\n'


ll k,d , t;

double can(double time)
{
    double tmp = time / (k + d - k % d) ;
    ll cil = tmp;

    double p = 1.0 * cil * k / t + (1.0 * cil* (d - k % d) ) / ( 2 * t) ;
    double left = time - cil * (k + d - k % d) ;
    if(left < k) {
         p += 1.0 * left / t ;
         left -= left;
    }
    else if(left >= k){
         p += 1.0 * k / t ;
         left -= k;
         p += 1.0 * left / 2 / t ;
    }

   // p += (time - tmp * (k + d - k % d)) *  1.0  * k / t;
    return p;
}
int main()
{
    //clock_t z = clock();
   // READ;
    cin >> k >> d >> t;
    if(k % d == 0) {
        cout << t << endl;
        return 0;
    }
    double lo = 0 , hi =  4 * 1e18;
    double mid;
    for(int i = 0; i < 200 ; i++){
         mid = (lo + hi)/ 2;
        if(can(mid) > 1 ){
            hi = mid;
        }
        else
            lo = mid;
    }

    printf("%.10f",mid);

    //printf("Total Time: %.3f\n", (double)(clock() - z) / CLOCKS_PER_SEC);

    return 0;
}
