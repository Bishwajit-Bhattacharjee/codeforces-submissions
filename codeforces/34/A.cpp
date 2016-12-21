#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e6;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
   int n;
   int a[110];
   cin >> n;
   loop(i, 0, n-1)
     cin >> a[i];
    int mini = abs (a[n-1]-a[0]);
    int id1 = 0, id2 = n-1;
    loop(i, 0, n-2)
    {
        if(abs(a[i] - a[i+1]) < mini)
        {
            mini = abs(a[i]-a[i+1]);
            id1 = i, id2 = i+1;
        }
    }
    cout << id1 + 1 <<' ' << id2+1 <<'\n';

   end ;
}


