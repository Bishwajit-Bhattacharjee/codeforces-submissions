#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = -1e9 -1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int ans = up, temp1, temp2;
   int n, k;
   cin >> n >> k;
   while(n--)
   {
       cin >> temp1 >> temp2;
       (temp2 > k)?ans = max(ans,temp1-temp2+k):ans= max(ans, temp1);
   }
   printf("%d\n", ans);

    return 0;

}
