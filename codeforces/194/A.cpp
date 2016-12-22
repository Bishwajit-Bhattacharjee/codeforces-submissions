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
  int n, k, n2 ,r, q;
  cin >> n >> k;
  q =  k / n;
  r = ( k % n);
  n2 = n - (k % n);
  if(q > 2)
    n2 = 0;
 cout << n2 << endl;
   end ;
}


