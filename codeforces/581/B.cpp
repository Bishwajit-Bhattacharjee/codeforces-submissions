
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =  1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e8;
using namespace std;

//global variables




int main(){
    //int n1, n2 ;
    int n;
    int a[array_size], maxi[array_size], mark[array_size];
    memset(maxi, -1, sizeof maxi);
    memset(mark, 0 ,sizeof mark);
    cin >> n;
    loop(i, 1,n)
    {
        scanf("%d", &a[i]);

    }
   // maxi[n] = a[n];
    for(int i = n; i > 0; i--){
        if(i != n)
        {
            maxi[i] = max(maxi[i+1], a[i]);
            if(maxi[i+1] == a[i]) mark[i] = 1;
        }
        else
            maxi[i] = a[i];
    }
    loop(i, 1, n)
    {
        int print;
         (maxi[i] - a[i]) == 0?print = 0:print = (maxi[i] - a[i]) + 1;
         if(mark[i]) print++;
        printf("%d ", print);
    }
    return 0;
}
