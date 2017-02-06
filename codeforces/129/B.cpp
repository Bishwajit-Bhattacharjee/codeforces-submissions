#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    //vector < int > adj[110];
    int r[110][110]={0};
    int a[110] = {};
    int n, m, t1, t2 ;
    int cnt  =0;
    cin >> n >> m;
    for(int i = 1; i <= m;i++)
    {
        scanf("%d %d", &t1, &t2);
       // adj[t1].pb(t2);
       // adj[t2].pb(t1);
       r[t1][t2] = 1;
       r[t2][t1] = 1;
        a[t1]++;a[t2]++;
    }
    while(1)
    {
      vector <int> v;
      for(int i = 1; i <=n; i++)
         if(a[i] == 1)
            v.pb(i), a[i]--;
      for(int i = 0; i < v.size(); i++)
        for(int j = 1; j <= 100; j++)
            if(r[v[i]][j])
              a[j]--;

      if(v.empty())
        break;
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}
