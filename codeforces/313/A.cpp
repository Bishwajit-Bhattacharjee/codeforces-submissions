#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int n, ans1, ans2, ans3 , ans;
   cin >> n;
 //  printf("%d", a % 10);
 if( n > 0)
    printf("%d\n", n);
 else
 {
     ans1 = n;
     ans2 = (n / 10);
     ans3 = (ans2 /10) * 10 + (ans1 %10);
     ans = max(ans1, max(ans2, ans3));
     printf("%d\n", ans);

 }

      return 0;

}
