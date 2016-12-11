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
  int n, m;
  scanf("%d %d",&n, &m);
  if(n > m)
    swap(n,m);
    if((n % 2)== 0)
        puts("Malvika");
      else
        puts("Akshat");

  return 0;
}
