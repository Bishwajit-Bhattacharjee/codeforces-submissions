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

    int da, db;
    cin >> da >> db;

    if(da == db) {
        cout << da << "0 " << db << "1" << endl;
    }
    else if(db == da + 1) {
        cout << da << " " << db << endl;
    }
    else if(da == 9 and db == 1) {
        cout << "9 10\n";
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
