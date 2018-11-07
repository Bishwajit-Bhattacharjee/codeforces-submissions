#include <bits/stdc++.h>
using namespace std;
int const MX = 2e7 ;
typedef long long int ll;
map < int,int > mp;
bool isPrime[MX] ;
vector < int > prime;
void sieve()
{
    fill(isPrime,isPrime + MX,1);
    isPrime[1] = isPrime[0] = 0;
    for(ll i = 2; i * i < MX ; i++)
    {
        if(isPrime[i]){
            //prime.push_back(i);
            for(int j = i*2; j < MX; j += i )
                isPrime[j] = 0;
        }
    }
    for(int i = 1; i < MX; i++)
        if(isPrime[i])
            prime.push_back(i);
}
void fact(int n)
{
    for(auto x : prime){
        if(1LL*x * x > n )break;
        if(n % x == 0){
            mp[x]++;
            while(n % x == 0) n /= x;
        }
    }
    if(n>1)
        mp[n]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > v(n);
    sieve();
    ll gcd = 0;
//    for(int i = 0; i < 100; i++)
//        cout << prime[i] << " " ;//[i == 99] ;
    for(int i = 0; i < n;i++)
    {
        cin >> v[i] ;
        gcd = __gcd(gcd,1LL*v[i]);
        //cout << gcd << endl;
    }
    for(int i = 0; i < n; i++)
        v[i] /= gcd;

    for(auto x : v){
        fact(x);
    }
    int ans = n;
    for(auto x : mp){
        //cout << x.first << endl;
        ans = min(ans,n - x.second);
        //cout << ans << endl;
    }

    cout << ((ans!=n)?ans:-1) << endl;
    return 0;
}
