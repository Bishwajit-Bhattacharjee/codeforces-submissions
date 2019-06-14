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
int const N = 3e6;

int mxdivi[N] ;
bool notPrime[N] ;
vector< int > primes;
void pre()
{
    memset(mxdivi,-1,sizeof mxdivi);

    for(int i = 2; i < N; i++){
        for(int j = 2 * i ; j < N; j += i)
            mxdivi[j] = i;
    }

    for(int i = 2; i < N; i++){
        if(!notPrime[i]){
            for(int j = 2 * i; j < N; j += i)
                notPrime[j] = 1;
        }
    }

    for(int i = 2; i < N; i++){
        if(!notPrime[i])
            primes.push_back(i);
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    pre();

    int n;
    cin >> n;

    vector < int > v(2*n);
    vector < int > ans;
    multiset < int > nonPrimes, mulprimes, mst;

    for(int i = 0; i < 2 * n; i++){
        cin >> v[i];
        //mst.insert(-v[i]);
        if(notPrime[v[i]]){
            nonPrimes.insert(-v[i]);
        }
        else {
            mulprimes.insert(v[i]);
        }
    }

    while(!nonPrimes.empty()){
        auto it = nonPrimes.begin();

        int val = *it;
        nonPrimes.erase(nonPrimes.begin());

        int corres = mxdivi[-val] ;
        //cout << corres << " " << val << endl;

        if(notPrime[corres]){
            nonPrimes.erase(nonPrimes.find(-corres));
        }
        else
            mulprimes.erase(mulprimes.find(corres)) ;
        ans.push_back(-val);
    }

    while(!mulprimes.empty()){
        int val = *(mulprimes.begin()) ;
        ans.push_back(val);
        mulprimes.erase(mulprimes.begin());
        mulprimes.erase(mulprimes.find(primes[val-1]));
    }

    //assert(ans.size() == n) ;

    for(auto v : ans)
        cout << v << " " ;
    cout << endl;




    return 0;
}
