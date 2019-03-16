//HK HK HK HK HK 108 times
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define all(x) x.begin(),x.end()
#define sz(x) ((int)x.size())
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
using namespace std;
const int mod = 1e9 + 7 ;
long long bigmod(long long p,long long e,long long M){
    long long ret = 1;
    for(; e > 0; e >>= 1){
        if(e & 1) ret = (ret * p) % M;
        p = (p * p) % M;
    } return ret;
}
template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
 ll modinverse(ll a,ll M){return bigmod(a,M-2,M);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
int const N = 1e6 + 10;


struct node
{
    int s, f, sf,fs;
    node(){
        s = f  = sf = fs = 0;
    }
    node(int a,int b,int c,int d)
    {
        f = a, s = b, fs = c, sf = d;
    }

};
int lazy[4*N];
node seg[4*N] ;

node combine(node a, node b)
{
    node tmp;
    tmp.s = a.s + b.s;
    tmp.f = a.f+b.f;
    tmp.fs = max(a.f + b.s, max(a.f + b.fs, max(a.fs,max(a.fs + b.s,b.fs))));
    tmp.sf = max(a.s + b.f, max(a.s + b.sf, max(a.sf,max(a.sf + b.f,b.sf))));
    return tmp;
}
string s;

int L(int x)
{
    return 2 * x;
}
int R(int x)
{
    return 2 * x + 1;
}
void build(int pos,int l, int r)
{
    if(l == r) {
        seg[pos] = node(s[l-1] == '4',s[l-1] == '7',0,0);
        return;
    }
    int mid = ( l + r) /2 ;

    build(L(pos),l, mid);
    build(R(pos),mid + 1, r);
    seg[pos] = combine(seg[L(pos)] , seg[R(pos)]) ;
}

void push(int pos, int l, int r)
{
    if(lazy[pos])
    {
        swap(seg[pos].f, seg[pos].s);
        swap(seg[pos].fs, seg[pos].sf);

        if(l != r){
            lazy[L(pos)] ^= 1;
            lazy[R(pos)] ^= 1;
        }
        lazy[pos] = 0;
    }
}

void update(int pos,int l,int r,int ul,int ur)
{
    if(lazy[pos]){
        push(pos,l,r);
    }
    if(l > ur or r < ul ) return;

    if(ul <= l and r <= ur)
    {
        lazy[pos] ^= 1;
        push(pos,l,r);
        return ;
    }
    int mid = (l+r) / 2;
    update(L(pos), l,mid,ul,ur);
    update(R(pos),mid+1,r,ul,ur);
    seg[pos] = combine(seg[pos*2] , seg[pos*2 + 1]);
}

node Q(int pos,int l,int r,int ql,int qr)
{
    if(lazy[pos]) {
        push(pos,l,r);
    }
    if(l > qr or r < ql)
    {
        return node();
    }
    if(ql <= l and r <= qr)
        return seg[pos] ;

    int mid = (l + r) / 2;
    return combine(Q(L(pos),l,mid,ql,qr), Q(R(pos),mid+1,r,ql,qr));

}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);

    memset(lazy,0,sizeof lazy);

    int q, n;
    cin >> n >> q >> s;
    //cout << s << endl;
    build(1,1,n);
    //cin.ignore('\n');
    while(q--)
    {
        string t;
        int a,b;
        //cin.ignore('\n');
        cin >> t;

        //cout << t << endl;
        if(t[0] == 's'){

            cin >> a >> b;
            //cout << a << " " << b << endl;
            update(1,1,n,a,b);
            //cin.ignore();
        }
        else {
            //cin.ignore();
            node tmp = Q(1,1,n,1,n);
            cout << max(tmp.f,max(tmp.s,tmp.fs)) << '\n';
        }
    }
    return 0;
}
