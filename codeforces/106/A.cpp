#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
#define end return 0
int main()
{
  map < char, int > x;
  x['6'] = 1; x['7'] = 2; x['8'] = 3;x['9']= 4; x['T']= 5; x['J'] = 6; x['Q'] = 7; x['K'] =8; x['A'] =9;
  string s1, s2, s3;
  char buf[10];
  cin >> s1;
  gets(buf);
  cin >> s2 >> s3;
  if(s2[1] == s3[1])
  {
      (x[s2[0]] > x[s3[0]])?puts("YES"):puts("NO");
      end;

  }
  else if(s2[1] == s1[0])
  {
      puts("YES");
  }
  else
    puts("NO");

   end ;
}


