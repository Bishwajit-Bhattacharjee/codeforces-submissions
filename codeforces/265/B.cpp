
#include <bits/stdc++.h>

using namespace std;
//map <string, string> a;

int main()
{
   //vector <int> v;
  int ara[100005];
  //vector< int>u(100005, 0);

  int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%d", &ara[i]);
        //u[ara[i]]++;
      //  v.push_back(t);
    }


     int count = ara[0] +1 ;

   for(int i = 0;i < n-1; i++)
   {
    count += abs(ara[i]-ara[i+1]) + 2;
   }
   printf("%d\n", count);
    return 0;
}



