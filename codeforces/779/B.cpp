#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const inf =   1 << 28 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
ll const MOD = 1e5 + 7;
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s >> n;
   // cout << s << n;
   int cnt = 0, it = 0;
   for(int i = s.size()-1; i >= 0 ; i--)
   {
       if(cnt == n)
        break;
       if(s[i] == '0')
        cnt++;
       it++;

   }
   int ans ;
   if(cnt < n)
        ans = s.size() - 1;
    else
        ans =  it - cnt;
    cout <<  ans;

}
