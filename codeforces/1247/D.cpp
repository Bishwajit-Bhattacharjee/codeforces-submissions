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

vector < int > fact[N] ;
vector < PLL > cnt[N] ;
bool mark[N];
int antiP[N] ;
vector <int > primes;

PLL p[N] ;

void seive()
{
    for(int i = 2; i < N; i++)
    {

        if(!mark[i]){
            for(int j = i ;j < N ; j += i ) fact[j].push_back(i) , mark[j] = (j != i);
        }
    }
    for(int i = 2; i < N; i++) if(!mark[i]) primes.push_back(i), antiP[i] = (int)primes.size() - 1;


    //cout << "ascho" << endl;//;
    for(int i = 2; i < N; i++)
    {
        for(auto f : fact[i]){
            int times = 0, tmp = i;
            while(tmp % f == 0) times++, tmp /= f;
            cnt[i].push_back({f,times});
        }
    }

    p[0] = {1,1} ;

    for(int i =1 ; i < N; i++)
        p[i] = (p[i-1]* base) % M;

}

PLL Hash(ll num, ll k)
{
    PLL h = {0,0};

    for(auto x : cnt[num])
    {
        h = (h +  p[antiP[x.first]] * (x.second % k)) % M;
    }
    return h;
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);

    seive();

    int n, k ;
    cin >> n >> k;

    vector < int > v(n);

    //for(int i = 2; i <= 20; i++) cout << i << " " << antiP[i] << endl;
    for(int i = 0; i < n; i++) cin >> v[i] ;

    map < PLL, ll > mp;
    vector < PLL > hh;
    ll ans = 0;
    for(int i = 0; i < n; i++) hh.push_back(Hash(v[i],k)), mp[hh.back()]++;

    for(int i = 0; i < n; i++)
    {
        PLL nh = {0,0};

        for(auto x : cnt[v[i]])
        {
            nh = (nh +  p[antiP[x.first]] * ( (k - x.second%k)%k)) % M;
        }
        //cout << i << " " << nh <<" " << hh[i] << endl;
        ans += mp[nh];
        if(nh == hh[i]) ans--;
    }
    ans /= 2;
    cout << ans << endl;
    return 0;
}
