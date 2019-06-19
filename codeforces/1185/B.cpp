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


int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    int n;
    cin >> n;
    while(n--){
        string a,b;
        cin >> a >> b;
        a += ')' , b += ')';
        vector < PII > av,bv;
        char last = '#';
        int cnt = 0;

        for(int i = 0; i < a.size(); i++) {
            if(a[i] == last and last != '#') {
                cnt++;
            }
            else if(a[i] == last and last == '#'){
                cnt = 1, last = a[i] ;
            }
            else {
                //cout << last << " " << cnt << endl;
                if(cnt){
                    av.push_back({last,cnt});

                }
                cnt = 1, last = a[i];
            }
        }
        a = b;
        last = '#', cnt = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] == last and last != '#') {
                cnt++;
            }
            else if(a[i] == last and last == '#'){
                cnt = 1, last = a[i] ;
            }
            else {
                //cout << last << " " << cnt << endl;
                if(cnt){
                    bv.push_back({last,cnt});

                }
                cnt = 1, last = a[i];
            }
        }

        if(av.size() == bv.size()) {
            bool f = 1;
            for(int i = 0; i < av.size(); i++){
                if(av[i].first != bv[i].first or av[i].second > bv[i].second){
                    cout << "NO\n";
                    f = 0;
                    break;
                }

            }
            if(!f){
                    continue;
                }
            cout << "YES\n";
            continue;

        }
        else{
            cout << "NO" << '\n';
        }
    }
    return 0;
}
