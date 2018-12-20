#include <bits/stdc++.h>
using namespace std;

struct dat
{
    int a,b,c;
    dat(){}
    dat(int x,int y,int z):a(x),b(y),c(z){

    }
};
int const N = 3e5 + 10;
int dp[N] ;
typedef pair < int, int > PII;

int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector < dat > edge(m);
    for(int i = 0; i < m; i++)
    {
        cin >> edge[i].a >> edge[i].b >> edge[i].c;
    }

    sort(edge.begin(),edge.end(), [](dat &a, dat &b)
         {
            return a.c < b.c ;
         });


    for(int i = 0; i < edge.size(); )
    {
        vector < PII > update;
        dat now = edge[i] ;
        update.push_back({dp[now.a] + 1,now.b});
        //update.push_back({dp[now.b] + 1,now.b});
        while((i + 1 ) < edge.size() and edge[i+1].c == edge[i].c)
        {
            i++;
            dat next = edge[i] ;
            update.push_back({dp[next.a] + 1,next.b});
        }

        for(auto x : update)
        {
            dp[x.second] = max(dp[x.second], x.first);
        }
        i++;
    }

    cout << *max_element(dp,dp + N) << '\n';
    return 0;
}
