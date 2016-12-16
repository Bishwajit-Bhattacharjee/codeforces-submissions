#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5 +5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
  int n, a, b;
  vector< PII > x;

  cin >> n;
  loop(i, 0, n-1)
  {
    cin >> a >> b;
    x.push_back(make_pair(a, b));
  }

  int cnt = 0;

  loop(i, 0 ,n-1)
  {
    bool c1 =false , c2 = false, c3 = false , c4 = false;
    loop(j,0, n-1)
    {
        if(i != j)
        {
            if(x[i].first==x[j].first && x[i].second < x[j].second)
                c1 = true;
            else if(x[i].first==x[j].first && x[i].second > x[j].second)
                c2 = true;
            else if(x[i].first < x[j].first && x[i].second == x[j].second)
                c3 = true;
            else if(x[i].first > x[j].first && x[i].second == x[j].second)
                c4 = true;
        }
    }
    if(c1 && c2 && c3 && c4)
        cnt++;
  }
  cout << cnt <<endl;
   return 0;
}
