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
   int n, a[11]={0},  l, s;
   cin >> n;
   loop(i, 0, n-1)
   {
      //scanf("%d", &a[i % 3]);
      cin >> l;
      a[i % 3] += l;
   }
   if(a[0] > a[1] && a[0] > a[2])
     puts("chest");
   else if(a[1] > a[0] && a[1] > a[2])
    puts("biceps");
   else
    puts("back");

    return 0;

}
