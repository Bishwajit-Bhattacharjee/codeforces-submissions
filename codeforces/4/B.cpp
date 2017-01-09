#include <bits/stdc++.h>

using namespace std;


int main() {
  /* code */
//
//vector <  pair < int , int > > v;
  int a1[34], a2[34], t1, t2, rsum;
 int d, sumtime;
  int s_min =0 , s_max = 0;

 cin >> d >> sumtime;

 for(int i = 0; i < d;i++)
 {
     cin >> t1 >> t2;
     a1[i] = t1;
     a2[i] = t2;
     s_min += t1;
     s_max += t2;

 }
 //bool f = true;
 if(sumtime > s_max || sumtime < s_min)
    {
        puts("NO");
        return 0;
    }
    int x = 0;
  rsum = s_max;
  bool f =true;
  while(rsum != sumtime)
  {
      if(a2[x] == a1[x])
        x++;
     if(a2[x] > a1[x])
   {

      a2[x]--;
      rsum--;
   }
     if(x >= d)
       {
           f = false;
           break;
       }
  }
  if(x == d )
  {
      puts("NO");
      return 0;
  }
  if(rsum == sumtime)
  {
      puts("YES");
      for(int i = 0; i < d; i++)
        cout << a2[i] << ' ';

    return 0;
  }
  puts("NO");



  return 0;
}
