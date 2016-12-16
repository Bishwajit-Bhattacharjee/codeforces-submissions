#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5 +5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
    int n ;
    cin >> n;
    if(n % 2 == 1)
    {
        puts("-1");
        return 0;
    }
    else
    {
        while(n)
            printf("%d ", n--);
    }
   return 0;
}
