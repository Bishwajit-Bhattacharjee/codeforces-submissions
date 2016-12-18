#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e-9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;


int main()
{
  int s1, s2, s3;
  cin >> s1 >> s2 >> s3;
  int a = (sqrt((1.0*s1*s2)/(1.0 * s3))+up);
  int b = (sqrt((1.0*s1*s3)/(1.0 * s2))+up);
  int c = (sqrt((1.0*s3*s2)/(1.0 * s1))+up);
  cout << 4*(a+b+c) << endl;
   return 0;
}
