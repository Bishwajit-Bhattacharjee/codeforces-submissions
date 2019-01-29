#include <bits/stdc++.h>
using namespace std;
int const N = 2e5 + 10;

typedef pair < int, int > PII;
#define F first
#define S second
vector < int > pd[N];
typedef long long int ll;
bool mark[N] ;
void create()
{
    for(ll i = 2; i < N; i++)
    {
        if(!mark[i]){

            for(ll j = i ; j < N; j += i )
            {
                mark[j] = 1;
                pd[j].push_back(i);
            }
        }
    }
}

map < PII, int > mp1,mp2;
vector < int > g[N];
int ara[N] ;
int parent[N];

void help(int r, int pr)
{
    parent[r] = pr;

    for(auto v : g[r])
        if(v  != pr) help(v,r);

}
int dfs(int root,int prime, int par)
{
    if(mp1.count({root, prime}))
        return mp1[{root,prime}];

//    //mp[{root, prime}] = 0;
    if(ara[root] % prime != 0 )
    {
        return mp1[{root,prime}] = 0;
    }

    ll tmp = 1;
    for(auto v : g[root])
    {
        if(v != par and ara[v] % prime == 0)
        {
            dfs(v,prime,root);
            //mp1[{root,prime}] = max()
            tmp = max(tmp, 1LL + mp1[{v,prime}]);
        }
    }
    return mp1[{root,prime}] = tmp;

}

int dfs1(int r, int par)
{

    int mx = 1;

    for(auto x : pd[ara[r]])
    {
        int tmp = 0;
        vector < int > vt;
        for(int v : g[r])
        {
            if(v != par)
            {
                vt.push_back(dfs(v,x,r));
            }
        }
        sort(vt.begin(),vt.end(), greater < int > ());

        if(vt.size() >= 2){
            tmp = 1 + vt[0] + vt[1];
        }
        else if(vt.size()) {
            tmp = 1 + vt[0];
        }
        else
            tmp = 1;
        mx = max(tmp, mx);

//        cout << "number : " << ara[r] << "\n";
//
//        for(auto x : vt)
//            cout << x << " " ;
//        cout << endl;
    }
    return mx;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    create();

    int n;
    cin >> n;
    int cnt = 0;
    for(int i =1 ; i <= n; i++){
        cin >> ara[i] , cnt += (ara[i] == 1);

//        for(int x : pd[ara[i]])
//            cout << x << " ";
//        cout << endl;
    }


    for(int i = 1; i <= n - 1; i++)
    {

        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    help(1,-1);
    int ans = 0;
    for(int i = 1; i <= n; i++)
        ans = max(ans, dfs1(i,parent[i]));
    if(cnt == n)
        return cout << "0",0;

    cout << ans << endl;
    return 0;
}
