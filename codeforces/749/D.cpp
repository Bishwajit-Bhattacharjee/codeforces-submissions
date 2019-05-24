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
set < ll > st[N];
set < PLL > active;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < ll > mx(n+1,-1);
    for(int i = 0; i < n;i++)
    {
        ll a,b;
        cin >> a >> b;
        mx[a] = b;
        st[a].insert(b);
    }
    for(int i = 1; i <= n; i++){
        if(mx[i] != -1)
            active.insert({mx[i],i});
    }

    int q;
    cin >> q;
    while(q--){
        int k;
        cin >> k;
        vector < ll > del(k);
        for(int i = 0; i < k; i++){
            cin >> del[i] ;
            if(mx[del[i]] != -1)
                active.erase({mx[del[i]], del[i]});

        }
        auto it = active.end();

        if(active.size() > 1){
            it--;
            auto nit = (it);
            //it;
            nit--;
            //cout << (*it) << " " << (*nit) << endl;
            cout  << (it->second) <<" " <<  *(st[(*it).second].upper_bound(nit->first)) <<  '\n';

        }
        else if(active.size() == 1){
            it--;
            cout << it->second << " " << *(st[(*it).second].upper_bound(0))  << '\n';
        }
        else {
            cout << "0 0" << '\n';
        }

        for(auto x : del){
            if(mx[x] != -1)
                active.insert({mx[x],x});
        }
    }
    return 0;
}
