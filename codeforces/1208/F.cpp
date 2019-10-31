#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;

typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define F first
#define S second
ostream& operator<<(ostream & os, PLL h)
{
	return os << "( " << h.F << ", " << h.S << " )" << endl;

}
PLL operator+ (PLL a, ll x)     {return {a.F + x, a.S + x} ;}
PLL operator- (PLL a, ll x)     {return {a.F - x, a.S - x} ;}
PLL operator* (PLL a, ll x)     {return {a.F * x, a.S * x} ;}
PLL operator+(PLL x, PLL y) { return {x.F + y.F,x.S + y.S} ;}
PLL operator-(PLL x,PLL y) { return {x.F - y.F, x.S - y.S} ;}
PLL operator*(PLL x,PLL y) { return {x.F * y.F , x.S * y.S} ;}
PLL operator%(PLL x,PLL y) { return {x.F % y.F, x.S % y.S} ;}

PLL base = {37,41};
PLL M = {1e9+21, 1e9+9};

int const N = 21;
vector < int > dp[(1<<N) + 5] ;//]
int const LOG = 21;

void DO(int s, int i)
{

    for(auto x : dp[s^(1<<i)]){
        dp[s].push_back(x);
    }
    sort(dp[s].begin(), dp[s].end(), greater<int>());

    while(dp[s].size() > 2){
        dp[s].pop_back();
    }
    reverse(dp[s].begin(), dp[s].end());//)
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    int n;
    while(cin >> n) {
        vector < ll > v(n);

        //memset(dp,0,sizeof dp);
        for(int i = 0; i < (1<<N); i++) dp[i].clear();

        for(int i = 0; i < n; i++) {
            cin >> v[i] ;
            dp[v[i]].push_back(i);
            if(dp[v[i]].size() > 2) dp[v[i]].erase(dp[v[i]].begin());
        }

        for(int i = 0; i < LOG; i++){
            for(int s = (1<<LOG)-1; s >= 0; s--){
                if(!(s & (1<<i)) ){
                    //dp[s] += dp[s^(1<<i)] ;
                    DO(s,i);
                }
            }
        }

        ll ans = 0;

        for(int i = 0; i < n; i++){
            ll can = 0 ;
            if(dp[0].size() >= 2 and i < dp[0][0]){
                can = v[i] ;
            }
            
            ll mask = 0;
            for(int bit = LOG-1; bit >= 0; bit--){
                if(can & (1<<bit)) continue;
                

                if(dp[mask^(1<<bit)].size() >= 2 and i < dp[mask^(1<<bit)][0]) 
                    mask ^= (1<<bit);
                
            }
            ans = max(ans, can | mask);
        }
        cout << ans << endl;
    }
    return 0;
}
