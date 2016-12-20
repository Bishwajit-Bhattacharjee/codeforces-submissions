#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
    int d, k;
    cin >> k >> d;
    if( d == 0 && k != 1)
        puts("No solution");
    else
    {
        cout << d ;
        k--;
        while(k--)
            cout << '0';
        cout << endl;
    }



    return 0;
}


