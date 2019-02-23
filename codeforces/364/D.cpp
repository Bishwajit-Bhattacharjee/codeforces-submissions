#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()
#include <chrono>

int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if (b == 0)
        return 1 % MOD;
    ll x = bigmod(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2)
        x = (x * a) % MOD;
    return x;
}

int const N = 1e6 + 10;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

vector < ll > ara(1e6 + 10);
int n;
ll ans;
set < int > seen;

ll cnt[90000];

void do_it_babe()
{
    int ind = ((rand() * RAND_MAX + rand()) % n) + 1;
    //cout << ind << endl;
    if(seen.find(ind) != seen.end()) return ;
    seen.insert(ind);
    ll num = ara[ind] ;
    vector < ll > divi;
    //cout << "here" << endl;
    for(ll x = 1; x * x <= num; x++)
    {
        if(num % x == 0 ) {
            divi.push_back(x);
            if(num / x != x ){
                divi.push_back(num/x);
            }
        }

    }
    sort(divi.begin(), divi.end());

    memset(cnt,0,sizeof cnt);

    for(int i = 1; i <= n; i++)
    {
        cnt[(int)(lower_bound(divi.begin(),divi.end(),__gcd(num,ara[i]))- divi.begin())]++;
    }

    for(int i = 0; i < divi.size(); i++)
    {
        for(int j = i+1; j < divi.size(); j++)
        {
            if(divi[j] % divi[i] == 0)
            {
                cnt[i] += cnt[j] ;
            }
        }
    }

    for(int i = 0; i < divi.size(); i++)
    {
        if(cnt[i] * 2 >= n)
        {
            ans = max(ans, divi[i]);
        }
    }

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 // */
    srand(time(0));
    clock_t ck = clock();

    cin >> n;
    //cout << n  << '\n';
    for(int i = 1; i <= n; i++)
        cin >> ara[i] ;

    int cc = 10;
    while ((clock() - ck) < 3.4 * CLOCKS_PER_SEC)
    {
        do_it_babe();
    }
    cout << ans << '\n';
    //while

    return 0;
}
