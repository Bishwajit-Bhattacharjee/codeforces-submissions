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
bool isfound8(int n)
{
    int r;
    if(n  < 0) n *= -1;
    while(n!=0)
    {
        r = n % 10;
        n /= 10;
        if(r == 8)
            return true;
    }
    return false;
}

int main()
{
  int n ;
   //string s;
  cin >> n;
  int ans = 0;
  do{
    ++n;

    //cout << s ;
    ans++;
  }while(!isfound8(n));
   cout << ans << endl;
   return 0;
}
