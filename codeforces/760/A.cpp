#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up =  5 * 1e5 + 10 ;
int const up1 = 1e3 + 10;
using namespace std;



int main()
{
     int m, d;
     cin >> m >> d;
     if(m == 2)
        m = 28;
     else if(m ==4 || m == 6 || m == 9 || m==11)
        m = 30;
     else
        m = 31;
     m -= (7 - d + 1);
     int ans = ( m % 7== 0)?(m/7):(m/7)+1;
     cout << ans + 1 <<  endl;

  return 0;
}
