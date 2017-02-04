#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e4 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    char s[110][20], buf[10];
    int n, b[110], a[110];
    scanf("%d", &n);
    gets(buf);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s %d %d", s[i], &b[i], &a[i]);
    }
    /*for(int i = 1; i <= n; i++)
    {
        printf("%s %d %d\n", s[i], b[i], a[i]);
    }*/
    for(int i = 1; i <= n; i++)
    {
        if(b[i] >= 2400 && (a[i] > b[i]))
        {
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}
