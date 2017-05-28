// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1000 + 10;
int const mod = 1e9 + 7;
using namespace std;


int main()
{
    int n;
    cin >> n;
    int ec = 0;
    while(n--)
    {
        int t;
        scanf("%d", &t);
        if(t % 2 == 0)
          ec++;
        if(ec % 2 == 0)
            puts("2");
        else
            puts("1");

    }
    return 0;
}
