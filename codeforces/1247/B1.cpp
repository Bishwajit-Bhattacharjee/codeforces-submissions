#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;
int const N = 2e5 + 10;
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


int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        int n,k,d;
        cin >> n >> k >> d;

        map < int,int > bought;
        vector < int > ara(n);

        int ans = d;

        for(int i = 0; i < n; i++) cin >> ara[i];

        int can = 0;

        for(int i = 0; i < d; i++){
            bought[ara[i]]++;
            if(bought[ara[i]] == 1){
                can++;
            }
        }
        ans = min(ans,can);

        for(int i = d; i < n; i++)
        {
            bought[ara[i]]++;
            if(bought[ara[i]] == 1) can++;

            bought[ara[i-d]]--;
            if(bought[ara[i-d]] == 0) can--;
            ans = min(ans, can);
        }
        cout << ans << "\n";
    }
    return 0;
}
