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
    int n,temp, k;
    cin >> n >> k;
    int cnt = 0;
    loop(i, 0, n-1)
    {
        cin >> temp;
        if(temp <= (5-k))
            cnt++;

    }
    printf("%d\n", cnt/3);

   return 0;

}
