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

int main()
{
    char ch1 = '{', ch2 = '}', ch3 = ',';
   char str[1010];
   int a[27]={0};
   gets(str);
   int len = strlen(str);
   loop(i, 0, len)
   {
       if(str[i]!=ch1&&str[i]!=ch2&&str[i]!=ch3 &&str[i]!=' ')
       {
         a[str[i]-'a']++;
       }
   }
       int cnt = 0;
       loop(i, 0, 25)
       {
           if(a[i])
            cnt++;
       }

    printf("%d\n", cnt);
  return 0;

}
