#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;

#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
  string a;
  //gets(a);
  cin >> a;
  int c = a.find("WUB");
  while(c != -1)
  {
      a = a.replace(c,3," ");
      c = a.find("WUB");
  }
 // printf("%s\n", a);
 cout << a << endl;
  return 0;
}
