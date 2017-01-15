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
    int n;
    char a[up1];
    cin >> n;
    char ch = 'a';
    int x =0;
    for(int j = 1; j <= 4; j++)
    {
        for(int i = x + 1; i <= n ; i+=4)
       {
          a[i] = ch;
       }
       ch++;x++;
    }
    for(int i = 1; i <= n; i++)
        printf("%c", a[i]);
  return 0;
}
