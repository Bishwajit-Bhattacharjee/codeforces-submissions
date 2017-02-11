
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end


int main()
{
    string s;
    cin >> s;
    int val =0 ;
    int len = s.size();
    for(int i = 0; i < len;i++)
    {
       val = min(s[i]-'0', 9 - (s[i]-'0'));
       if(val == 0 && i ==0)
         val = 9;
       s[i] = '0' + val;
    }
    cout << s ;
    return 0;
}
