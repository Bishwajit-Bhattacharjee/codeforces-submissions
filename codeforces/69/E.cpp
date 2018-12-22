#include <bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define F first
#define S second
#define FAST ios::sync_with_stdio(0);cin.tie(0)
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}
bool operator==(PLL x,PLL y) { return x.F == y.F and x.S == y.S ;}
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

int const INF = 1e9 + 100;
int n,k;
int const N = 1e5 + 5;
ll seg[4*N];
void update(int pos, int l,int r,int ind,int val)
{
    if(l == r and r == ind)
    {
        seg[pos] = val;
        return;
    }
    if(l > ind or r < ind) return ;
    int mid = (l+r)/2;

    update(pos*2,l,mid,ind,val);
    update(pos*2+1,mid+1,r,ind,val);
    seg[pos] = max(seg[pos*2] , seg[pos*2+1]);
}

ll Q(int pos,int l,int r,int ql,int qr)
{
    if(l >= ql and r <= qr)
    {
        return seg[pos];
    }
    if(l > qr or r < ql)
        return -INF;
    int mid = (l+r) / 2;

    return max(Q(pos*2,l,mid,ql,qr),Q(pos*2+1,mid+1,r,ql,qr));

}
int main()
{
    FAST;
    //int n, k;
    cin >> n >> k;
    map < int, int > last,cnt;

    vector < int > v(n+1);

    for(int i =1 ; i <= n; i++)
        cin >> v[i] ;
    bool f = 0;
    for(int i = 1; i <= n; i++)
        update(1,1,n,i,-INF);

    for(int i = 1; i <= n; i++)
    {
        cnt[v[i]]++;

        if(cnt[v[i]] == 1){
            update(1,1,n,i,v[i]);

        }
        else if(cnt[v[i]] == 2){
            update(1,1,n,last[v[i]],-INF);
        }

        //if(i >= k) f = 1;
        last[v[i]] = i;
        if(i > k)
        {
            int j = i - k;
            cnt[v[j]]--;
            if(cnt[v[j]]== 1){
                update(1,1,n,last[v[j]],v[j]);
            }
        }
        if(i >= k)
        {
            ll ans = Q(1,1,n,i-k+1,i) ;//
            //<< '\n';
            if(ans == -INF)
            {
                cout << "Nothing" << '\n';
            }
            else
                cout << ans << '\n';
            //cout << ((ans == -INF)? "Nothing" : ans) <<'\n' ;
        }
    }
    return 0;
}
