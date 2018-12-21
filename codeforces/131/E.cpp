#include <bits/stdc++.h>
using namespace std;
#define pb push_back

struct dat
{
    int a,b,c;
    dat(){}
    dat(int x, int y, int z):a(x),b(y),c(z)
    {

    }
    bool operator==(const dat &rhs)const
    {
        return c == rhs.c;
    }
};
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m ;
    cin >> n >> m;
    map < int, vector < dat >  > row, col,dig1,dig2;
    int ans[10] ;
    memset(ans,0,sizeof ans);
    vector < int > cnt(m+1,0);
    for(int i = 0; i < m; i++)
    {
        int a,b;
        cin >> a >> b;
        dat tmp = dat(a,b,i);
        row[a].pb(tmp);
        col[b].pb(tmp);
        dig1[a+b].pb(tmp);
        dig2[a-b].pb(tmp);
    }

    for(auto& x : row)
    {        sort(x.second.begin(),x.second.end(),
                  [] (dat &p,dat &y)
                  { return p.b < y.b ;});
    }

    for(auto& x : col)
    {
        sort(x.second.begin(),x.second.end(),[] (dat &p, dat &y)
             {
                return p.a < y.a;
             });
    }

    for(auto& x : dig1)
    {
        sort(x.second.begin(),x.second.end(),[] (dat &p, dat &y)
             {
                return p.a < y.a;
             });
    }

    for(auto& x : dig2)
    {
        sort(x.second.begin(),x.second.end(),[] (dat &p, dat &y)
             {
                return p.a < y.a;
             });
    }

    for(auto x : row)
    {
        if(x.second.size()==1)
            continue;
        for(auto y : x.second)
        {
            if( !(y == x.second[0]) and !(y == x.second.back()) )
                cnt[y.c] += 2;
            else
                cnt[y.c]++;
        }
    }

    for(auto x : col)
    {
        if(x.second.size()==1)
            continue;
        for(auto y : x.second)
        {
            if( !(y == x.second[0]) and !(y == x.second.back()) )
                cnt[y.c] += 2;
            else
                cnt[y.c]++;
        }
    }

    for(auto x : dig1)
    {
        if(x.second.size()==1)
            continue;
        for(auto y : x.second)
        {
            if( !(y == x.second[0]) and !(y == x.second.back()) )
                cnt[y.c] += 2;
            else
                cnt[y.c]++;
        }
    }
    for(auto x : dig2)
    {
        if(x.second.size()==1)
            continue;
        for(auto y : x.second)
        {
            if( !(y == x.second[0]) and !(y == x.second.back()) )
                cnt[y.c] += 2;
            else
                cnt[y.c]++;
        }
    }

    for(int i = 0; i < m; i++)
        ans[cnt[i]]++;

    for(int i = 0; i <= 8; i++)
        cout << ans[i] << ' ';
    cout << endl;
    return 0;

}
/***
10 10
6 5
3 5
3 4
6 10
3 10
4 6
6 2
7 5
1 8
2 2
***/

/*** 0 5 1 2 1 1 0 0 0 ***/
