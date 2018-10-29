#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = 1e5 + 10;
int par[MX] ;
int sz[MX] ;
void make_set(int n)
{
    for(int i = 1; i <= n; i++)
        par[i] = i,sz[i] = 1;//;
}
int Find(int n)
{
    return par[n] = (par[n] == n) ? n : Find(par[n]) ;
}
void Union(int u,int v)
{
    int a = Find(u);
    int b = Find(v);
    if(a != b){
        par[b] = a;
        sz[a] += sz[b] ;
    }
}
bool lucky(int n)
{
    while(n){
        int t = n % 10;
        if(t != 4 and t != 7)
            return 0;
        n /= 10;
    }
    return 1;
}

ll noLucky(int x,int n)
{
    ll here = sz[x] ;
    if(here < 2)
        return 0LL;

    return ( here * (here - 1) * 2 * (n - here)) + (here * (here -1 ) * (here-2)) ;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n;
    cin >> n;
    make_set(n);
    for(int i = 1; i <= n-1; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(!lucky(c)){
            Union(a,b);
        }
    }

    set < int > s;
    for(int i =1 ; i <= n; i++)
        s.insert(Find(i));
    ll ans = n * (n - 1) * (n - 2);

    for(auto x : s )
    {
        ans -= noLucky(x,n);
    }
    cout << max(0LL, ans) << endl;

    return 0;
}
