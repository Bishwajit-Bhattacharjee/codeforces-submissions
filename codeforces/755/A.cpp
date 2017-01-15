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
bool is_prime(int n)
{
  for(int i  =2; i * i <= n; i++)
  {
      if(n % i == 0)
        return 0;
  }
  return 1;
}

int main()
{
    int n ;
    cin >> n;
   // if(is_prime(2))


        for(int i = 1; i <= 1000; i++)
        {
            if(!is_prime(n * i + 1))
            {

               printf("%d", i);
               break;
            }

        }


   return 0;
}
