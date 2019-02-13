#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()
#include <chrono>

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;//;

int counter;


int read(int val, bool type)
{
    if(!type){
        cout <<"? " << val << endl;
    }
    else {
        cout <<"> " << val << endl;
    }
    int ret;
    cin >> ret;
    return ret;
}

int find_max()
{
    int lo = 0, hi = 1e9 ;

    while(lo < hi)
    {
        int mid = (lo + hi) / 2;
        int ret = read(mid,1);

        counter++;
        if(ret){
            lo = mid + 1;
        }
        else {
            hi = mid;
        }
    }
    return lo;
}
int n;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int find_d()
{
    assert(counter <= 60);
    vector < int > v;
    set < int > taken;
    int howmany = 0 ;
    int id ;

    while(counter < 60 and howmany < n)
    {
        id = ( rng() % n ) + 1;
        while(taken.find(id) != taken.end()){
            id = (rng() % n ) + 1;
        }
        taken.insert(id);
        v.push_back(read(id,0));
        counter++;
        howmany++;
    }

    sort(v.begin(),v.end());
    int ans = 0;

    for(int i = 1; i< v.size(); i++)
        ans = __gcd(ans, v[i] - v[i-1]);
    return ans;
}

int main()
{
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    srand(time(0));




    cin >> n;



    ll mx = find_max();
    ll d = find_d();
    cout << "! " << mx - (n-1)* d << " " << d << endl;

    return 0;
}



