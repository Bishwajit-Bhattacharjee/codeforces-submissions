/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int const INF = 100010;

struct habibi
{
    int mn, id,tot;
    habibi(){

    }
    habibi(int a,int b,int c):mn(a),id(b),tot(c){

    }
    void printing(){
        cout << "  " << mn << " " << id << " " << tot << endl;
    }
};

habibi seg[INF*4];
int ara[INF] ;

habibi merge(habibi& a,habibi& b)
{
    habibi tmp ;
    tmp.tot = a.tot + b.tot;
    if(a.mn < b.mn){
        tmp.mn = a.mn;
        tmp.id = a.id;
    }
    else if(b.mn < a.mn)
    {
        tmp.mn = b.mn;
        tmp.id = b.id;
    }
    else{
        tmp.mn = a.mn;
        tmp.id = min(a.id,b.id);
    }
    return tmp;
}

void build(int pos,int l,int r)
{
    if(l == r)
    {
        seg[pos] = habibi(ara[l],l,1);
        return;
    }
    int mid = (l + r) / 2;
    build(2*pos,l,mid);
    build(2*pos +1, mid+1, r);
    seg[pos] = merge(seg[pos*2],seg[pos*2 + 1]);
}

void update(int pos,int l,int r,int un,int val)
{
    if(l > un or r < un)
        return;
    if(l == r and r == un){
        seg[pos] = habibi(val,un,0);
        return;
    }
    int mid = (l + r) / 2;
    update(2*pos,l,mid,un,val);
    update(2*pos +1, mid+1,r,un,val);
    seg[pos] = merge(seg[pos*2],seg[pos*2 + 1]);

}

habibi query(int pos,int l,int r,int ql,int qr)
{
    if(ql > r or qr < l ) 
        return habibi(INF,0,0);
    if(ql <= l and r <= qr)
        return seg[pos];
    int mid = (l + r) / 2;
    habibi c1 = query(2*pos,l,mid,ql,qr);
    habibi c2 = query(2*pos +1, mid+1,r,ql,qr);
    //seg[pos] = merge(seg[pos*2],seg[pos*2 + 1])
    return merge(c1,c2);
}
int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    
    int n;
    cin >> n;

    for(int i = 1; i <= n;i++)
        cin >> ara[i] ;
    build(1,1,n);

    ll move = 0LL;
    int last = 0;
    for(int i = 1; i <= n; i++)
    {
        habibi pura = query(1,1,n,1,n);
        habibi baki = habibi(INF,0,0);
        /*cout << "pura " ;
        pura.printing();
        */

        if(last != n)
            baki = query(1,1,n,last + 1,n);
/*        cout << " baki " ;
        baki.printing();
*/        if(pura.mn < baki.mn){
            move += baki.tot;
            move += query(1,1,n,1,pura.id).tot;
            update(1,1,n,pura.id,INF);
            last = pura.id;
        }
        else if(pura.mn == baki.mn) {
            move += query(1,1,n,last+1,baki.id).tot;
            last = baki.id;
            update(1,1,n,baki.id,INF) ;
        }
//        cout << "ei dhape " << move << endl;

    }
    cout << move << endl;


    return 0;
}