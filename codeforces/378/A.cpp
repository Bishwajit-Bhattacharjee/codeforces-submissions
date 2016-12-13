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
   int a, b;
   cin >> a >> b;
   int c1 = 0,c2 =0, c3 = 0;
   for(int i = 1; i <= 6;i++)
   {
       if(abs(i-a) < abs(i-b))
        c1++;
       else if(abs(i-a) > abs(i-b))
        c2++;
       else
        c3++;
   }
   cout << c1 <<' '<< c3 <<' '<< c2 << endl;
    return 0;

}
