/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 1000000007
#define endl '\n'

/*template <class T> inline T gcd(T a,T b){if(b==0)return a;return gcd(b,a%b);}
ll bigmod(ll base, ll pow)
{
    if(pow == 0) return (1 % mod);
    ll x = bigmod(base, pow/2 );
    x = ( x * x ) % mod;
    if(pow % 2 == 1)
         x = (x * base) % mod;
    return x;
}
*/
int const SZ = 1e5 + 10;
int seg[4*SZ][26];
int lazy[4*SZ][26];
string s;

void build(int pos,int l,int r)
{
    if(l == r){
        for(int i = 0; i < 26; i++){
            seg[pos][i] = (s[l-1] == (i+'a'));
        }
        return;
    }

    int mid = ( l + r) / 2;
    build(2*pos,l,mid);
    build(2*pos+1,mid + 1,r);

    for(int i = 0;i < 26;i++){
        seg[pos][i] = seg[pos*2][i] + seg[2*pos+1][i] ;
    }
}

void push(int pos,int id,int l,int r)
{
    
    seg[pos][id] = (r-l+1) * lazy[pos][id];
    if(l != r){
        lazy[pos*2][id] = lazy[pos][id] ;
        lazy[pos*2+1][id] = lazy[pos][id] ;
        lazy[pos][id] = -1;
    }
    
}
void update(int pos,int id,int l,int r,int ul,int ur,int val)
{
    if(lazy[pos][id] != -1)
        push(pos,id,l,r);
    if(l > ur or r < ul)
        return;
    if(ul <= l and r <= ur){
        seg[pos][id] = (r - l + 1) * val;
        lazy[pos][id] = -1;
        if(l != r){
            lazy[pos*2][id] = val ;
            lazy[pos*2+1][id] = val ;
        }
        return;
    }
    int mid = (l + r) / 2;

    update(pos*2,id,l,mid,ul,ur,val);
    update(pos*2+1,id,mid+1,r,ul,ur,val);
    seg[pos][id] = seg[pos*2][id] + seg[pos*2+1][id];
}

int query(int pos,int id,int l,int r,int ql,int qr)
{
    if(lazy[pos][id] != -1)
        push(pos,id,l,r);

    if(l > qr or r < ql)
        return 0;
    if(ql <= l and r <= qr)
        return seg[pos][id];

    int mid = (l + r) / 2;

    return query(pos*2,id,l,mid,ql,qr) + 
    query(pos*2+1,id,mid+1,r,ql,qr);

}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    memset(lazy,-1,sizeof lazy);

    int n,q;
    cin >> n >> q;
    cin >> s;
    build(1,1,s.size());

    while(q--)
    {
        int l,r,k;
        cin >> l >> r >> k;
        int from;
        if(!k){
            from = r;
        }
        else {
            from = l;
        }

        for(int i = 0; i < 26; i++)
        {
            int cnt = query(1,i,1,s.size(),l,r);
            //cout << i << " " << cnt << endl;

            if(cnt){
                update(1,i,1,s.size(),l,r,0);
                if(!k){
                    update(1,i,1,s.size(),from-cnt+1,from,1);
                    from -= cnt;
                }
                else {
                    update(1,i,1,s.size(),from,from + cnt -1,1);
                    from += cnt;
                }
                //cout << i << " matha theke bolchi " << query(1,i,1,s.size(),l,r) << endl;
            }

        }
    }
    string ans = "";

    for(int i = 1; i <= s.size(); i++)
    {
        for(int j = 0; j < 26; j++)
        {
            int cnt = query(1,j,1,s.size(),i,i);
            //cout << j << " " << cnt << endl;
            if(cnt){
    //            ans[i] = 'a' + j;
                ans += ('a'+j);
            }
        }
    }

   
    cout << ans <<  endl;

    return 0;
}