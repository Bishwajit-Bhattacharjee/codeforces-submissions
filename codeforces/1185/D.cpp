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
int const N = 3e5 + 10;

bool arith(vector < int > v)
{
    sort(v.begin(),v.end());
    if(v.size() <= 1 ) return 1;
    set < int > st;
    for(int i = 1; i < v.size(); i++){
        st.insert(v[i] - v[i-1]);
    }
    return st.size() == 1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    vector < PII > v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i].first ;
        v[i].second = i+1;
    }
    sort(v.begin(), v.end());

    if(n < 1000) {

        for(int i = 0; i < n; i++){
            vector < int > tmp;
            for(int x = 0; x < n; x++){
                if(x != i)
                    tmp.push_back(v[x].first) ;
            }
            if(arith(tmp)){
                return cout << v[i].second , 0 ;
            }
        }
        cout << "-1";
    }
    else {
        //sort(v.begin(), v.end());

        vector < int > tmp1, tmp;

        for(int i = 0; i < n; i++){
            if(i != 0) tmp.push_back(v[i].first);
            if(i != 1) tmp1.push_back(v[i].first);
        }
        if(arith(tmp)){
            return cout << v[0].second , 0 ;
        }
        if(arith(tmp1)){
            return cout << v[1].second, 0;
        }

        ll d = v[1].first - v[0].first;

        vector < int > ans;

        multiset < ll > mst;
        for(int i = 0; i < n; i++){
            mst.insert(v[i].first);
        }
        for(ll cnt = 1; cnt <= n - 1; cnt++){
            ll elm = v[0].first + (cnt - 1) * d;

            auto it = mst.find(elm);
            if(it == mst.end()){
                return cout << "-1",0 ;
            }
            else {
                mst.erase(it);
            }
        }

        if(mst.size() == 1){
            auto it = mst.begin();
            ll e = *(it);
            for(int i = 0; i < n; i++){
                if(v[i].first == e) {
                    return cout << v[i].second << '\n', 0 ;
                }
            }
            assert(0);
        }
        else {
            cout << "-1";
        }
    }
    return 0;
}
