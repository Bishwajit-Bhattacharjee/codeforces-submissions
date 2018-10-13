#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll a,b,x,n;
ll const MOD = 1e9 + 7;

struct mat
{
    ll ara[2][2];

    void setter()
    {
        ara[0][0] = a % MOD ;
        ara[0][1] = ara[1][1] = 1;
        ara[1][0] = 0;
    }
    void identity()
    {
        for(int i = 0; i < 2; i++)
        {
            for(int j = 0; j < 2;j++)
                ara[i][j] = (i == j) ;
        }
    }
};

mat mul(mat &a,mat &b)
{
    mat tmp;
    tmp.identity();

    for(int i = 0; i < 2; i++)
    {
        for(int j =0 ; j < 2; j++)
        {
            tmp.ara[i][j] = 0;
            for(int k =0; k < 2; k++)
            {
                tmp.ara[i][j] += a.ara[i][k]*b.ara[k][j] ;
                tmp.ara[i][j] %= MOD ;
            }
        }
    }
    return tmp;

}
mat expo(mat a,ll pow)
{
    mat tmp, ans;
    ans.identity();
    tmp.identity();

    for(int i =0; (1LL << i) <= pow;i++)
    {
        if(i == 0)
            tmp = a;
        else 
            tmp = mul(tmp,tmp);
        if((1LL << i) & pow)
        {
            //cout << ans.ara[0][0] << endl;
            ans = mul(ans,tmp);
            //cout << ans.ara[0][0] << endl;

        }
    }
    return ans;
}
int main()
{

    cin >> a >> b >> n >> x;
    mat tmp;
    tmp.setter();
    //cout << tmp.ara[0][0] << endl;

    tmp = expo(tmp,n);
    //cout << tmp.ara[0][0] << endl;

    cout << (tmp.ara[0][0]*x + tmp.ara[0][1]* b ) % MOD << endl;

    return 0;

}
/*
3 4 1 1
3 4 2 1
3 4 3 1

*/