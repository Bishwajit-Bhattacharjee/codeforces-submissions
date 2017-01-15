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
     int n, m ;
     cin >> n >> m;

    set < string > s;
    string x;
    for(int i = 1 ; i <= (m+n); i++)
    {
        cin >> x;
        s.insert(x);
    }
    int a = m + n - s.size();
    n += (a - a / 2);
    m += (a/2);
    if(n > m)
        puts("YES");
    else
        puts("NO");
   return 0;
}
