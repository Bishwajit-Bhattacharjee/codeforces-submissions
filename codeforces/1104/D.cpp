#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair < int,int > PII;
typedef pair < ll,ll > PLL;
#define pb push_back
//#all(x) (x).begin(),(x).end()

//int const N = 1;
int const MOD = 1e9 + 7;

ll bigmod(ll a, ll b)
{
    if(b==0)
        return 1 % MOD;
    ll x = bigmod(a,b/2);
    x = (x * x) % MOD;
    if(b%2)
        x = (x * a) % MOD;
    return x;
}

int const N = 2e5 + 10;//;


char ret(int a,int b)
{
    cout << "?" << " " << a << " " << b << endl;
    char ch;
    cin >> ch;
    return ch;

}
void game()
{
    int x, y ;
    //x = 2, y = 1;
    int lo , hi , sm, big;
    sm  = hi = -1;

    for(int i = 1; i < 31; i++)
    {
        x = (1 << i) ; y = (1 << (i-1));
        if(ret(x,y) == 'y'){
            sm = y;
            big = x;
            break;
        }
    }
    if(sm == -1)
    {
        cout << "! 1" << endl;
        return ;
    }

    lo = sm, hi = big;

    while(hi - lo > 1)
    {
        int mid = (lo+hi)/2;
        char ch = ret(lo,mid);
        if(ch == 'y'){
            lo = mid ;
        }
        else {
            hi = mid;
        }
    }
    char ch = ret(lo,hi);
    if(ch == 'y'){
        cout << "! " << lo << endl;
    }
    else {
        cout << "! " << hi << endl;
    }
}
int main()
{

    string s;
    while(cin >> s and s == "start")
    {
        game();

    }
    return 0;
}


