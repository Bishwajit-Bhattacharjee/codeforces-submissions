#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e8 -1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   int n, a[110], l, s;
   cin >> n;
   loop(i, 0, n-1)
     cin >> a[i];
   int mini = up;
   loop(i, 1, n-2)
   {
       int maxi = -up;
       loop(k, 1, n-1)
       {
           l = k;s = k-1;
           if(k == i) l++;
           if(k == i+1) s--;
           maxi = max(maxi, a[l]-a[s]);

       }
       mini = min(mini, maxi);
   }
   printf("%d\n", mini);
    return 0;

}
