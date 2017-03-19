#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
ll const inf =  1LL << 59 ;
int  const MX  = 150010 ;
int const EPS = 1e-9;
int  const MOD = 1e9 + 7;
using namespace std;


int main(){
    vector < string > s;
    string s1;
    int n, k ;
    cin >> n >> k;
    
    int pos = 2;
    string s2 = "Aaa";
    
    for(int i = 1, j = 1;i <= n;  i++){
        
        if(i %  26 == 0)
          pos = 1, j = 1;
        s2[pos] += j;
        s.pb(s2);
        
    }
    
for(int i = 0; i < n - k + 1; i++)
   {
       cin >> s1;
       if(s1 == "NO")
          s[i+k- 1] = s[i];
   }
    for(int i =0;i < n; i++){
        cout << s[i] << ' ';
    }
    return 0;
}