#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e3 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
   PII arr[up];
   int s, n;
   cin >> s >> n;
   for(int i = 0; i < n; i++)
   {
       cin >> arr[i].first >> arr[i].second;
   }
   sort(arr, arr + n);
   bool flag = false;
   for(int i = 0; i < n; i++)
   {
       if(arr[i].first < s)
       {
        s+=arr[i].second;

       }
       else
       {
           flag = true;
           break;
       }
   }

   if(flag)
      printf("NO\n");
   else
    printf("YES\n");
   return 0;

}
