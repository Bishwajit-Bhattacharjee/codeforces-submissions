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
    int a[up];
    int sum[up] ;
    for(int i = 0; i < up ; i++)
        sum[i]  = 1 ;
    cin >> n;
    for(int i = 0; i < n; i++)
       scanf("%d", &a[i]);
    for(int i = 0; i < n; i++)
    {
        if(a[i] > a[i-1] && i)
             sum[i] += sum[i-1];

        for(int j = i ; j < n-1 ; j++)
        {
            if(a[i] == a[i-1] && i)
         {
             sum[i] = sum[i-1];
             break;
         }
            if(a[j] >= a[j+1])
            {
                sum[i]++;
            }
            if(a[j] < a[j+1])
                break;
        }
    }
   /* for(int i = 0 ; i < 100 ; i++)
    {
        printf("%d -> %d\n", a[i],sum[i]);
    } */
    cout << *std::max_element(sum, sum + n) << endl;
  return 0;
}
