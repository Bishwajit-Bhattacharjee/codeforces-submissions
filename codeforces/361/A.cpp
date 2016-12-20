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
    int n, k;
    cin >> n >> k;
    loop(i, 1, n)
    {
        loop(j, 1, n)
        {
            (i == j)?printf("%d ", k):printf("0 ");
        }
        printf("\n");
    }


    return 0;
}


