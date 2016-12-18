#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
    vector < int > o, e ,zero;
    int n, temp;
    cin >> n;
    loop(i, 0, n-1)
    {
        cin >> temp;
        if(temp == 0)
            zero.pb(temp);
        else if(temp > 0)
            e.pb(temp);
        else
            o.pb(temp);
    }
    int x0 = SZ(zero), x1 = SZ(o) ,x2 = SZ(e);
    printf("1 %d\n", o[0]);
    o.erase(o.begin());
    if(e.empty())
    {
        printf("2 %d %d\n", o[0],o[1]);
        o.erase(o.begin(), o.begin()+2);
    }
    else
    {
        printf("1 %d\n", e[0]);
        e.erase(e.begin());
    }
    printf("%d ", SZ(zero)+ SZ(o)+SZ(e));
    printf("0 ");
    loop(i, 0, o.size()-1)
    {
        printf("%d ", o[i]);
    }
    loop(i,0, e.size()-1)
    {
        printf("%d ", e[i]);
    }
     printf("\n");
   return 0 ;
}
