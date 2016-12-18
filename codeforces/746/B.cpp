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


int main()
{
    int n;
    char a[5000], buf[10];
    scanf("%d", &n);
    gets(buf);
    gets(a);
    char r[5000];
    if(n % 2 == 0)
    {
        int f = -1, j;
        int id = (n /2);
        for(int i = 0, j = 0; i < n; i++){
           r[id + f * j] = a[i];
           f = f * (-1);

           if(i % 2 == 0)j++;
        }

    }
    else{
        int f = 1;
        int id = (n/2) + 1;
        for(int i = 0, j = 0 ; i < n; i++){
            r[id + f * j] = a[i];
            f = f * (-1);
            if( i % 2 == 0)
                j++;
        }
    }
    for(int i = 1; i <= n; i++)
        printf("%c", r[i]);
    printf("\n");

   return 0 ;
}
