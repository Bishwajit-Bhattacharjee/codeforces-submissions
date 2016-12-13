#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e7 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int ans = 0, temp;
   int n, c ;
   vi(v);

   cin >> n >> c;
   loop(i, 0, n-1)
    {

     cin >> temp;
     v.pb(temp);
    }
    loop(i, 0, n-2)
    {
        ans = max(ans,v[i]-v[i+1]-c);
    }
    printf("%d\n", ans);
    return 0;

}
