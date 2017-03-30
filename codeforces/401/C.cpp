#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 2 *1e5 + 10;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


//int level[MX];
//int color[MX];


int main(){
    int n, m ;
    cin >> n >> m;
    if(n > m + 1  || m > (n + 1)* 2)
    {
        puts("-1");
        return 0;
    }
    int a[n * 3 + 100];
    memset(a , -1 , sizeof(a)) ;
    int i , j;
    for( i = 2, j = 1; j <= n; j++, i += 3){
        a[i] = 0;
    }
    i -= 3;

    for(int x = 3; x < i && (m > 0)  ; x += 3){
        a[x] = 1, m--;
    }
    // cout << m << endl;
    for(int x = 4; x < i && (m > 0) ; x += 3){
        a[x] = 1, m--;
    }
    //cout << m << endl;
        for(int x = 0 ; x < 2 && (m > 0) ; x++)
            a[x] = 1, m--;
      //      cout << m << endl;
        for(int x = i + 1; m > 0 ; x++)
            a[x] = 1, m--;
        //    cout << m << endl;
    for(int w = 0 ; w < 3 * n + 10; w++){
        if(a[w] != -1)
            printf("%d",a[w]);
    }
    return 0;
}
