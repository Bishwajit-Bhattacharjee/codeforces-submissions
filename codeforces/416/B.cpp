#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define pb push_back
int const up =  5 * 1e4 + 10 ;
int const up1 = 1e8 + 10;
using namespace std;
int o[up][5];
int n[up][5]= {0};
//vector < int > divi[100007];
int main()
{
    int num , m ;
    cin >> m >> num;
    for(int i =0 ; i < m; i++)
    {
        for(int j = 0;j  < num; j++)
          scanf("%d", &o[i][j]);
    }
    n[0][0] = o[0][0];
    for(int i = 1; i < num; i++)
        n[0][i] = o[0][i] + n[0][i-1];
    for(int  i = 1; i < m ; i++)
    {
        n[i][0] = o[i][0] + n[i-1][0];
        for(int j = 1; j < num; j++)
        {
            n[i][j] = max(n[i][j-1], n[i-1][j]) + o[i][j];
        }
    }

    for(int i = 0 ; i < m; i++)
    {
        //int sum = 0;
        //for(int j = 0; j < num; j++)
            //sum += n[i][j];
        printf("%d ", n[i][num-1]);
    }
  return 0;
}
