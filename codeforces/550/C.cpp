
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =  1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e5 + 7;
using namespace std;

//global variables
int i , j , k;
string s;
bool div()
{


     int x = s[k] - '0';int y= s[j] - '0'; int z = s[i] - '0';
   bool   f1 =  ((x * 100 + y * 10 + z ) % 8 == 0) ;

        return f1;
}

int main(){

     // string s;      p
      cin >> s;
      int n = s.size();
      for(int i = 0; i < s.size(); i++)
      {
          if((s[i] - '0') % 8 == 0)
          {
            puts("YES");
            cout << s[i];
            return 0;
          }
      }
      for(int i = s.size() - 1; i > 0 ; i--)
      {
          for(int j = i - 1; j >= 0; j--)
          {
              if(((s[i]-'0')+(s[j]-'0')*10) % 8 == 0)
              {
                  puts("YES");
                  cout << s[j] << s[i];
                  return 0;
              }
          }
      }
      for( i = s.size()-1; i > 1; i--)
      {
          for( j = i - 1; j > 0;j--)
            for( k = j - 1; k >= 0; k--)
          {
              if(div())
              {
                puts("YES");
               // printf("%c%c%c", s[k], s[j], s[i]);
               cout << s[k]<<s[j]<<s[i];
                return 0;
              }
          }
      }

    puts("NO");
    return 0;
}
