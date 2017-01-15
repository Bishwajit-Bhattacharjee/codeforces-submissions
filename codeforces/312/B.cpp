#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up =  5 * 1e4 + 10 ;
int const up1 = 1e5 + 10;
using namespace std;
int o[up][5];
//int n[up][5]= {0};
//vector < int > divi[100007];
int main()
{
    int a,b, c, d;
    cin >> a >> b >> c >> d;
    printf("%.10lf\n", (a*d*1.0)/(a*d*1.0+b*c*1.0-c*a*1.0));
  return 0;
}
