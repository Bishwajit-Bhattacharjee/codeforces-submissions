#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e3 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
    int n;
    cin >> n;
    vi(v1); vi(v2); vi(v3);
    loop(i, 1, n)
    {       int temp ;
            cin >> temp;
            if(temp == 1)
                v1.pb(i);
            else if(temp == 2)
                v2.pb(i);
            else
                v3.pb(i);
    }
    int l1 = SZ(v1);
    int l2 = SZ(v2);
    int l3 = SZ(v3);
    int mini = min(l1, min(l2, l3));
    printf("%d\n", mini);
    if(mini != 0)
    {
      for(int i =0; i< mini; i++)
        {
            printf("%d %d %d\n",v1[i], v2[i], v3[i]);
        }
    }
   return 0;

}
