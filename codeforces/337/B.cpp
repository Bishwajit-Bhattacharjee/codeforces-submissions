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
int gcd(int a, int b)
{
    int t;
    while(b != 0)
    {
       t = b;
       b = a % b;
       a = t;

    }
    return a;
}
int main()
{
    int a, b, c, d;
    cin >>  a >> b >> c >> d;

   // a = (a / gcd(a, b));
   // b = (b / gcd(a, b));
   // int x = gcd(c, d);
   // c = (c / x);
   // d = (d / x);
         if(a * d > c * b)
         {
             swap(a, c);
             swap(b, d);
         }
         if(a * d == c * b)
         {
             //cout << '0' ;
             printf("0/1");
             return 0;
         }

     int ans1 = (b*c-a*d) / gcd(b*c-a*d, b*c);
     int ans2 = (b*c) / gcd((b*c-a*d),(b*c));

     printf("%d/%d", ans1, ans2);
     // printf("\n%d %d %d %d", a, b ,c ,d);
   return 0;
}
