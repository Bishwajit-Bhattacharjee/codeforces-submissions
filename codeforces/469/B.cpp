#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e3;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
    vector < PII > x, y;
    int p , q, t1, t2,t3 , t4, l , r;
    scanf("%d %d %d %d", &p , &q, &l ,&r);
    loop(i, 0, p-1)
    {
        scanf("%d %d", &t1, &t2);
        x.pb(make_pair(t1, t2));
    }
    loop(i, 0, q-1)
    {
        scanf("%d %d", &t1, &t2);
        y.pb(make_pair(t1, t2));
    }
    set < int > cnt;
    for(int a = l; a <= r; a++)
    {
        bool f = false;
        for(int i = 0; i < q; i++)
        {
            for(int j = 0; j < p; j++)
            {
                if(y[i].first + a > x[j].second || y[i].second + a < x[j].first)
                    continue;
                else
                    cnt.insert(a);
            }
        }
    }
    cout << cnt.size() << endl;
    return 0;
}

