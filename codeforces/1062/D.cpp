#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;

typedef pair < int, int > PII;
#define F first
#define S second
vector < int > pd[N];
typedef long long int ll;
ll sum[N] ;
void create()
{
    for(ll i = 2; i < N; i++)
    {
        for(ll j = i*2 ; j < N ; j+= i)
            sum[j] += i;

    }
}


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    create();

    int n;
    cin >> n;

    ll ans = 0;

    for(int i = 2; i <= n; i++)
        ans += 1LL * sum[i] * 4;
    cout << ans << endl;

    return 0;
}
