#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e7 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
    int n, v, k, mini, temp, ara[55];
    cin >> n >> v;
    for(int i =0 ; i < n; i++)
    {
        cin >> k;
        mini = up;
        while(k--)
        {
            cin >> temp;
            mini = min(mini, temp);
        }
        ara[i] = mini;
    }
    int cnt = 0;
    loop(i, 0, n-1)
    {
        if(v > ara[i])
           cnt++;
    }
    printf("%d\n", cnt);
    if(cnt)
    {
        loop(i, 0, n-1)
        {
            if(v > ara[i])
                printf("%d ",i+1);
        }
        printf("\n");
    }

   return 0;

}
