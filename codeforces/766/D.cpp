#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;

PLL operator+(PLL a,PLL b){ return {a.first + b.first, a.second + b.second}; }
PLL operator-(PLL a,PLL b){ return {a.first - b.first, a.second - b.second}; }
PLL operator*(PLL a,PLL b){ return {a.first * b.first, a.second * b.second}; }
PLL operator/(PLL a,PLL b){ return {a.first / b.first, a.second / b.second}; }
PLL operator%(PLL a,PLL b){ return {( b.first + a.first) % b.first, (b.second + a.second) % b.second}; }
PLL operator%(PLL a,ll b){ return {a.first % b, a.second % b} ;}
PLL operator+(PLL a,ll b){ return {a.first + b, a.second + b} ;}
PLL operator-(PLL a,ll b){ return {a.first - b, a.second - b} ;}
PLL operator*(PLL a,ll b){ return {a.first * b, a.second * b} ;}

ostream& operator<<(ostream &out,PLL a)
{
    out << "( " << a.first << ", " << a.second << " )" ;
    return out;
}

/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/

typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

int const N = 2e5 + 100;
int par[N] ;
int foe[N] ;
int Find(int u)
{
    return par[u] = ((u == par[u])?u : Find(par[u])) ;
}
void ADD(int a,int b)
{
    int A = Find(a);
    int B = Find(b);

    if(A != B){
        par[A] = B;
    }
}
bool Union(int a,int b,int t)
{
    int A = Find(a);
    int B = Find(b);
    if(t == 1){
        if(A == B) return 1;
        if((foe[A] == B or foe[B] == A )){
            return 0;
        }
        ADD(A,B);
        if(foe[A] != -1 and foe[B] != -1){
            ADD(foe[A],foe[B]);

            foe[Find(foe[A])] = Find(A);
            foe[Find(A)] = Find(foe[A]);
        }
        else if(foe[A] != -1){
            foe[Find(foe[A])] = Find(A);
            foe[Find(A)] = Find(foe[A]);
        }
        else if(foe[B] != -1){
            foe[Find(foe[B])] = Find(A);
            foe[Find(A)] = Find(foe[B]);
        }

        return 1;
    }
    else {
        if(A == B) return 0;
        /// review
        if(foe[A] == B or foe[B] == A) return 1;

        if(foe[A] != -1)
            Union(foe[A],B,1);
        if(foe[B] != -1)
            Union(foe[B],A,1) ;

        foe[Find(A)] = Find(B);
        foe[Find(B)] = Find(A);
        return 1;
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n,m,q;
    cin >> n >> m >> q;
    memset(foe,-1,sizeof foe);

    map < string , int > mp;
    for(int i = 0;i < n; i++){
        string tmp;
        cin >> tmp;
        mp[tmp] = mp.size();
    }
    for(auto x : mp)
        par[x.second] = x.second;

    while(m--){
        int t;
        string a,b;
        cin >> t >> a >> b;
        cout << ( Union(mp[a],mp[b],t) ? "YES" : "NO") << '\n';
    }
    while(q--){
        string a,b;
        cin >> a >> b;
        int A = Find(mp[a]);
        int B = Find(mp[b]);
        int val = -1;
        if(A == B) {
            val = 1;
        }
        else if(foe[A] == B or foe[B] == A){
            val = 2;
        }
        else
            val = 3;
        cout << val << '\n';
    }
    return 0;
}
