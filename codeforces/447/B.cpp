#include <bits/stdc++.h>

#define char_to_num(ch) (ch-'0')
using namespace std;
int main()
{
    char str[1009];
    int k,  temp;
   //vector < int > v(26);
    int ara[27];
    gets(str);
    scanf("%d", &k);
    int maxi = 0;
    int n = 26;
    for(int i =0 ; i < 26; i++)
    {
        scanf("%d", &ara[i]);
       temp = ara[i];
        maxi = max(maxi, temp);
    }
   // sort(v.begin(), v.end());
 //   int maxi = v[v.size() - 1];
    int len = strlen(str), x, i;
    long long int ans = 0;
    //int maxi = *max_element(v.begin(), v.end());
    for(int i = 0; i < len; i++)
    {
        ans += (ara[str[i]-'a'])*(i+1);

    }
   for( i = 1, x = len + 1; i <= k ; i++)
   {
       ans += maxi * (x++);

   }

   printf("%I64d\n", ans);

	return 0;
}
