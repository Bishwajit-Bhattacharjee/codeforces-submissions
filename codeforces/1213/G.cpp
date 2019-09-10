#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct dat{
    int a,b,c;
    dat(){}
    dat(int x,int y,int z):a(x),b(y),c(z){

    }
    bool operator<(dat &rhs)const{
        return c < rhs.c;
    }

};

int const N = 2e5 + 20;

ll ans = 0;
int par[N];
ll sz[N] ;

ll Find(int id)
{
    return par[id] = ( (par[id] != id) ?Find(par[id]): id );
}

void Merge(dat e)
{
    int a = Find(e.a);
    int b = Find(e.b);

//    cout << "edge : " << e.a << " " << e.b << " " << e.c << endl;
//    cout << a << " " << b << endl;
//    //assert(a != b);

    ans += sz[a] * sz[b] ;

    par[b] = a;
    sz[a] += sz[b] ;

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<dat> e(n-1);

    for(int i = 0; i < N; i++)
        par[i] = i, sz[i] = 1;

    for(int i = 0; i + 1 < n; i++){
        int a,b,c;
        cin >> a >> b >> c;
        e[i].a = a;
        e[i].b = b;
        e[i].c = c;
    }

    sort(e.begin(),e.end());

    vector < pair < ll,ll > > q(m);

    vector < ll > qans(m);

    for(int i = 0; i < m; i++){
        cin >> q[i].first ;
        q[i].second = i;
    }

    sort(q.begin(),q.end());

    int id = 0;

    for(int i = 0; i < m; i++){

        while(id < e.size() and e[id].c <=  q[i].first) {
            Merge(e[id++]);
        }
        qans[q[i].second] = ans;

    }

    for(auto x : qans){
        cout << x << " " ;
    }
    cout << endl;
    return 0;
}
