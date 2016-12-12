#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e2 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
    int n, d, temp, ans;
    int sum = 0;
    cin >> n >> d;
    loop(i, 0, n-1)
     {
         cin >> temp;
         sum += temp;
     }
     sum += (n-1)*10;
     bool flag = false;
     if(sum > d)
        flag = true;
     else
     {
         ans = 2*(n-1) + (d - sum)/ 5;
     }
     flag?printf("-1\n"):printf("%d\n", ans);

   return 0;

}
