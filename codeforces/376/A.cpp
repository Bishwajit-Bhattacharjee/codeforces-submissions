#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e9;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
   char s[1000000];
   long long int id;
   scanf("%s", s);
   id =  strlen(s);
  long long int i  = std::find(s, s + id , '^') - s;
    long long int s_l = 0, s_r =0;
   // cout << i << endl;
    loop(l, 0,i-1)
    {
        if(isdigit(s[l]))
           s_l += (s[l]-'0') * (i-(long long int)l);
    }
   // cout << s_l << endl;
    loop(r, i+1, strlen(s)-1)
    {
        if(isdigit(s[r]))
            s_r += (s[r]-'0') *((long long int)r - i);
    }
   // cout << s_l << endl;
    if(s_l > s_r)
        puts("left");
    else if(s_l < s_r)
        puts("right");
    else
        puts("balance");
   end ;
}


