#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const N = 2e5 + 10;
ll par[2][N] ;
ll sz[2][N] ;

int Find(int p,int ind)
{
    return par[ind][p] = (par[ind][p] == p) ? p : Find(par[ind][p], ind);
}
void Union(int a,int b,int ind)
{
    int A = Find(a,ind);
    int B = Find(b,ind);
    if(A == B) return ;
    if(sz[ind][A] < sz[ind][B]) swap(A,B);
    par[ind][B] = A;
    sz[ind][A] += sz[ind][B] ;

}
int const MOD = 1e9 + 7;

ll bigmod(ll a,ll b)
{
    if(b==0) return 1;
    ll x = bigmod(a,b/2);
    x = (x * x ) % MOD;
    if(b & 1) x = (a * x) % MOD;
    return x;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int n;
    cin >> n ;
    for(int i =1; i <= n; i++) par[0][i] = par[1][i] = i, sz[0][i] = sz[1][i] = 1;

    for(int i = 0; i < n - 1; i++){
        int a,b, c;
        cin >> a >> b >> c ;
        Union(a,b,c);
    }
    ll ans = 0;

    for(int i = 1; i <= n; i++)
    {
        ans += sz[0][Find(i,0)] - 1;
        ans += sz[1][Find(i,1)] - 1;
        ans += 1LL*( sz[0][Find(i,0)] - 1) * (sz[1][Find(i,1)] - 1);
    }
    cout << ans << endl;
    return 0;
}
