#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;
typedef unsigned long long int ULL;
typedef pair<ULL,int> PUI;
#define S second
#define F first
typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


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

ostream& operator<<(ostream &out,PUI a)
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


int const MOD = 1e8 + 7;

int const N = 1e5 + 10;
bool mark[N] ;

void sieve()
{
    for(int i = 2; i < N; i++){
        if(!mark[i]){
            for(int j = 2 * i ; j < N; j += i) 
                mark[j] = 1;
        }
    }
}

ll bigmod(ll a, ll b, ll mod = MOD){

    if(b == 0) return 1LL;
    ll x = bigmod(a,b/2);
    x = (x * x ) % mod;
    if(b & 1) x = (x * a) % mod;
    return x;
}

ll ___gcd(ll a, ll b)
{
    if(a == 0 or b == 0) return b + a;
    return __gcd(a,b);
}

bool isSub(string &s, string &t)
{
    int sid = 0, tid;
    for( tid = 0; tid < t.size(); tid++){
        
        if(sid >= s.size()) break;
        while(sid < s.size() and s[sid] != t[tid]){
            sid++;
        }
        sid++;
    }

    
    return tid >= t.size();
}

bool isSubSequence(string  str1, string str2) 
{ 
   int m = str1.size() ;
   int n = str2.size(); 
   int j = 0; // For index of str1 (or subsequence 
  
   // Traverse str2 and str1, and compare current character  
   // of str2 with first unmatched char of str1, if matched  
   // then move ahead in str1 
   for (int i=0; i<n&&j<m; i++) 
       if (str1[j] == str2[i]) 
         j++; 
  
   // If all characters of str1 were found in str2 
   return (j==m); 
} 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    string ss, s,t, tt;
    //ss = '$', tt = '$';

    cin >> s >> t;
    //s += '#';
    //t += '#';
    ss += s, tt += t;

    string tmp ;

    ll ans = 0;

    for(int i = 0; i < s.size(); i++){
        for(int j = i; j < s.size(); j++){
            tmp = s.substr(0,i) + s.substr(j+1);
            //if(tmp.size() < 1) continue;
            if(isSubSequence(t,tmp)) {
                //cout << i << " " << j << " " << tmp << endl;
                ans = max(ans, 1LL*j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}