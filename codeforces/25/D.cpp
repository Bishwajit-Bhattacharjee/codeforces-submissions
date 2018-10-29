//cf25D.cpp
#include <bits/stdc++.h>
using namespace std;
int const MX = 1010;
set < int > ps;
int par[MX] ;
typedef pair <int,int> PII;

void make_set(int n)
{
    for(int i = 1; i <= n; i++)
        par[i] = i, ps.insert(i);
}
int Find(int u)
{
    return par[u] = ((u == par[u])?u : Find(par[u]));
}
vector < PII > edge;

void Union(int u,int v)
{
    int a = Find(u);
    int b = Find(v);
    if(a == b){
        edge.push_back({u,v});
    }
    else if(a != b)
    {
        ps.erase(a);
        par[a] = b;
    }
}
int main()
{
    ios::sync_with_stdio(false);//)
    cin.tie(0);

    int n;
    cin >> n;
    make_set(n);

    for(int i = 1; i <= n - 1;i++){
        int a,b;
        cin >> a >> b;
        Union(a,b);

    }
    vector < int > left;

    for(auto x : ps)
        left.push_back(x);

    cout << edge.size() << endl;
    //assert(edge.size() ==)
    if(edge.size())
    {
        assert(edge.size() + 1 == left.size());

        for(int i = 0; i < edge.size(); i++)
        {
            cout << edge[i].first << " " << edge[i].second << " "
                << left[i] << " " << left[i+1] << '\n';
        }
    }
    //for(int i = )

    return 0;
}
