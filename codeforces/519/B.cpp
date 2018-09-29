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
//#define DEBUG(x) cout <<" #(x) <<
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)
#define FAST ios_base::sync_with_stdio(false)
#define ll long long
#define MOD 1000000007
#define endl '\n'



int main()
{
    int xor1 = 0, xor2 = 0, xor3 = 0;
    
    
    int n;
    cin >> n;
    //int
    for(int i = 1; i <= n; i++)
    {
        int tmp;
        cin >> tmp;
        xor1 ^= tmp;
    }
    for(int i = 1; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        xor2 ^= tmp;
    }
    for(int i = 1; i + 1 < n; i++)
    {
        int tmp;
        cin >> tmp;
        xor3 ^= tmp;
    }
    cout << (xor1 ^ xor2) << endl << (xor2 ^ xor3) << endl;
    
    return 0;
}
