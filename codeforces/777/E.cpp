#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
int const MX = 1e5 + 10;
typedef long long int ll;
ll seg[4*MX] ;
typedef pair < ll,ll > PLL;


/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

void update(int p,int l,int r,int nd,ll val)
{
    if(nd > r or nd < l )
        return ;
    if(l == r and r == nd){
        seg[p] = val;
        return;
    }
    int mid = (l+r) / 2;
    update(p*2,l,mid,nd,val);
    update(p*2 +1,mid + 1,r,nd,val);
    seg[p] = max(seg[p*2],seg[p*2 +1]) ;
}
ll Q(int p,int l,int r,int ql,int qr)
{
    if(l > qr or r < ql ) return 0;
    if(ql <= l and r <= qr)
        return seg[p] ;
    int mid = (l+r) / 2;
    ll q1 = Q(p*2,l,mid,ql,qr);
    ll q2 = Q(p*2+1,mid+1,r,ql,qr);
    //seg[p] = max(seg[p*2],seg[p*2+1]);
    return max(q1,q2);
}

struct node
{
    ll a,b,h;
    node(int x, int y,int z):a(x),b(y),h(z){

    }
    node(){
    }
};

vector < node > B;
vector < pair < node,int > > A;
typedef pair < node,int > pnt ;

bool comp(node x, node y)
{
    return x.b < y.b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map < ll , PLL > mp;
    for(int i = 0; i < n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        if(mp.count(b)){
            mp[b].first = min(mp[b].first,a*1LL);
            mp[b].second += c;
        }
        else
            mp[b] = {a,c};

        //B.push_back(node(a,b,c));
    }

    for(auto x : mp){
        B.push_back(node(x.second.first,x.first, x.second.second));
    }
    sort(B.begin(),B.end(), comp);

    int sz = B.size();

    vector < ll > ans(sz);
    ordered_set ost;
    //cout << sz << endl;
    for(int i = 0; i < sz; i++)
    {
        int from = ost.order_of_key(B[i].a + 1) ;
        //cout << i << " " << from << endl;
        ll candi = Q(1,0,sz-1,from, i);
        ans[i] = B[i].h + candi ;
        update(1,0,sz-1,i,ans[i]) ;
        ost.insert(B[i].b);
    }
    cout << *max_element(ans.begin(),ans.end()) << endl;
    return 0;
}
