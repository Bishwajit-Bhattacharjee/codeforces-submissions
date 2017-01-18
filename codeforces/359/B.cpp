#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e7 + 10 ;
int const up1 = 1e5+ 10;
using namespace std;

int main()
{
   int a[up1];
   int n, k, j;
   cin >> n >> k;
   for(int i = 1; i<= 2 * n; i++)
     a[i] = i;
    for(int i = 1,  j = 1; j <= k;j++, i+=2)
    {
        swap(a[i], a[i+1]);
    }
    for(int i =1; i <= 2 * n ; i++)
        printf("%d ", a[i]);
    return 0;
}

