// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   1e2 + 10;
int const mod = 1e9 + 7;

using namespace std;

int dp[MX][2][2];
int a[MX];
int n;

int f(int i , int con, int gym)
{
    if(i == n)
        return 0;
    int &ret = dp[i][con][gym];
    if(ret != -1)
        return ret;
    if(a[i] == 0)
        ret = 1 + f(i+1 , 0 , 0);
    if(a[i] == 1){
        if(!con)
         ret = min(f(i+1, 1, 0), 1+ f(i + 1, 0 , 0));
        else
        ret = 1 + f(i+1 , 0 , 0);
    }
    else if(a[i] == 2){
        if(!gym)
            ret = min(f(i+1, 0, 1), 1 + f(i + 1, 0 , 0 ));
        else
            ret = 1 + f(i +1, 0 , 0);
    }
    else if(a[i] == 3){
        if(con && gym){
            ret = 1 + f(i + 1, 0 , 0 );
        }
        else if(con){
            ret = min(f(i+1, 0 ,1), 1 + f(i + 1, 0 , 0 ));
        }
    }
}

int main()
{

  int a,d;

  string s;
  cin >> a ;
  char ch;
  while(cin>> ch && ch != 'e'){
    if(ch != '.')
    s += ch;
  }
  cin >> d;
  //cout << a << ' ' << s << ' ' << d;
//  puts(s);
   if(s.size() <= d){
    cout << a << s;
    for(int i = 1; i <= d - s.size(); i++)
        cout << '0';
    return 0;
   }
   else {
     cout <<a ;
     for(int i = 0; i < d; i++){
        cout << s[i];
     }
     int c = 0;
     for(int i = d; i < s.size(); i++){
        c += s[i] - '0';
     }
     if(c){
         cout << '.';
        for(int i = d; i < s.size(); i++)
            cout << s[i];
     }
   }

   return 0;
}
