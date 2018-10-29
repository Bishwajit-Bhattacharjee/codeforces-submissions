#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int const MX = 2e5 + 10;
vector < ll > next_empty(MX);
ll cap[MX] ;
ll has[MX] ;
int n;

void make_set(int n)
{
    for(int i = 1; i <= n;i++)
        next_empty[i] = i;
    next_empty[n+1] = -1;
}

int next(int i,int x)
{
    if(i == -1)
        return -1;
    if(i == n + 1)
        return -1;
    if(cap[i] - has[i] > x){
        has[i] += x; return next_empty[i] = i;
    }
    if(cap[i] - has[i] == x){
        has[i] += x; return next_empty[i] = next_empty[i+1];
    }

    x -= (cap[i] - has[i]);
    has[i] = cap[i] ;
    //int now = i;
    return next_empty[i] = next(next_empty[i+1],x);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    //int n;
    cin >> n;
    make_set(n);
    for(int i = 1; i <= n; i++)
        cin >> cap[i] ;
    int m;
    cin >> m;
    while(m--)
    {
        int type;
        cin >> type ;
        if(type == 1){
            int p, x;
            cin >> p >> x;
            next_empty[p] = next(next_empty[p],x);
        }
        else {
            int k;
            cin >> k;
            cout << has[k] << '\n';
        }
    }
    return 0;
}
