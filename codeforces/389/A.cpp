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
 long long   gcd(long long  a, long long  b)
{
   // long long gcd(long long a, long long b)

	if(a == 0 || b == 0)return a + b;
	return gcd(b, a % b);

}

int main()
{
    int n, temp;
    cin >> n;
    int g = 0;
    loop(i, 0, n-1)
    {
       cin >> temp;
       g = gcd(g , temp);

    }
    cout << n * g << endl;
   return 0 ;
}
