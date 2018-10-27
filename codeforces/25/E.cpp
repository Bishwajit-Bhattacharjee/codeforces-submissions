#include <bits/stdc++.h>
using namespace std;

#define pb push_back
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

PLL M = {1000000021, 1e9 + 9 };
int const MX = 2e5 + 10;

PLL P[MX];
PLL h[MX][4];

int ara[] = {0,1,2};
vector < string > v(3);

PLL Hash(string &s)
{
    PLL hh = {0,0};

    for(int i = 0; i < s.size(); i++)
    {
        hh = (hh * base + (s[i] - 'a' + 1)) % M ;
    }
    return hh ;
}

PLL sub(int l,int r, int id)
{
    return ( (h[r][id] - (h[l-1][id]*P[r-l+1])) % M + M ) % M ;
}


int len(int id1, int id2)
{
    string s1 = v[id1] ;
    string s2 = v[id2] ;

    int mn = min(s1.size(),s2.size());
    int mil = 0;
    for(int i = (int)s1.size(); i > 0; i--)
    {
        int tmp = (int)s1.size() - i + 1;
        //cout << tmp << endl;

        if(tmp > mn)
            break;
        PLL h1 = sub(i,s1.size(),id1);
        PLL h2 = sub(1,1 + tmp - 1, id2);

        //cout << h1 << h2 << endl;

        if(h1 == h2){
            mil = max(mil,tmp);
        }
    }
    return (int)s1.size() + (int)s2.size() - mil ;

}

bool isSubstr(int id1, int id2)
{
    PLL puraHash = sub(1,v[id1].size(),id1);

    for(int i = 1; i + v[id1].size() - 1<= v[id2].size() ; i++)
    {
        PLL tmp = sub(i, i + v[id1].size() - 1, id2) ;
        if(tmp == puraHash)
            return 1;
    }
    return 0;
}

int solve()
{
    return ( len(ara[0], ara[1]) + len(ara[1], ara[2] ) - (int)v[ara[1]].size() ) ;
}
int main()
{

    P[0] = {1,1};

    for(int i = 1; i < MX; i++)
        P[i] = (P[i-1] * base) % M;

    for(int i = 0; i < 3; i++){
        cin >> v[i] , h[0][i] = {0,0};

        for(int j = 1; j <= v[i].size(); j++)
        {
            h[j][i] = (h[j-1][i] * base + (v[i][j-1] - 'a' + 1)) %  M;
            //cout << h[j][i] << endl;

        }
    }

    int ans = 0;

    for(int i =0; i < 3;i++)
        ans += v[i].size();

    for(int i = 0; i < 3; i++)
    {

        for(int j = 0; j < 3; j++)
        {
            if(i != j and isSubstr(i,j)){
                ans = len(j,3 - i - j);
                ans = min(ans,len(3 - i - j,j));
                return cout << ans << endl, 0;

            }
        }
    }

    do{
        int leni = solve();
        //cout << len << endl;

        ans = min(ans, leni);
    }while(next_permutation(ara,ara + 3));

    //cout << len(0,1) << endl;


    cout << ans << endl;
    return 0;

}
