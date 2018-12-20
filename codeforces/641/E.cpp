#include <bits/stdc++.h>
using namespace std;
map < int , int > time_map;
// get<Y>(X)
int const N = 1e5 + 10;

map < int ,int > bit[N] ;

struct dat
{
    int a,b,c;
    dat(){}
    dat(int x,int y,int z):a(x),b(y),c(z)
    {

    }
};

void insert(int t,int val)
{
    for(int i = t; i < N ; i += (i & -i))
        bit[i][val]++;
}
int remove(int t,int val)
{
    for(int i = t; i < N; i += (i & -i))
        bit[i][val]--;
}
int QR(int t,int val)
{
    int ans = 0;
    for(int i = t; i > 0; i -= (i & -i))
        ans += bit[i][val];
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector < dat > Q;
    vector < int > time;

    for(int i = 1; i <= n; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        Q.emplace_back(a,b,c);
        time.emplace_back(b);
    }
    sort(time.begin(), time.end());

    int id = 1;
    for(auto x : time )
    {
        time_map[x] = id++;
    }

    for(auto x : Q)
    {
        if(x.a == 1)
        {
            insert(time_map[x.b] , x.c);
        }
        else if(x.a == 2)
        {
            remove(time_map[x.b],x.c);
        }
        else
            cout << QR(time_map[x.b],x.c) << '\n';
    }
    return 0;
}
