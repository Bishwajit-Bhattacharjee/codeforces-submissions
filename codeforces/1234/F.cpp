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

int const N = 20 ;
int dp[5 + (1<<N)] ;

int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    string s;
    cin >> s;
    //cout << s << endl;

    for(int i = 0; i < s.size(); i++){
        //cout << "here "<< endl;
        int mask = 0, distinct = i;
        while(distinct < s.size() and ( (mask & (1<<(s[distinct]-'a')) ) == 0)){
            //cout << "here" << endl;
            mask ^=  (1 << (s[distinct] - 'a'));
            dp[mask] = __builtin_popcount(mask);
            distinct++;
        }

    }


    for(int i = 0; i < N; i++)
    {
        for(int s = (1<<N) - 1; s >= 0 ; s--){
            if(s & (1 << i)){
                dp[s] = max(dp[s], dp[s^(1<<i)]);
            }
        }
    }
    //cout << "acho" << endl;
    int ans = 0;
    for(int s = 0; s < (1<<N); s++){
        ans = max(ans, dp[s] + dp[(1<<N)-1-s]);
    }
    cout << ans << endl;

    return 0;
}
