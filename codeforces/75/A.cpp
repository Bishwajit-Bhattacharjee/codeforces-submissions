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
int removezero(int n)
{
    int ten=1, newn = 0, r ;
    while(n)
    {
        r = n % 10;
        n /= 10;
        if(r != 0)
        {
            newn += ten * r;
            ten *= 10;
        }
    }
    return newn;
}
int main()
{
    int a, b, c;
    cin >> a >> b;
    c = a + b;
    if(removezero(c) == removezero(a) + removezero(b))
        puts("YES");
    else
        puts("NO");
    return 0;
}


