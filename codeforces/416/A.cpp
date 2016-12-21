#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

//map <string, string> a;

int main()
 {
    char s[100], buf[10], ch1, ch2, ch3;
    int n, m;
    set < int > gr, sm;

    cin >> n;
    gets(buf);
    loop(i, 0, n-1)
    {
     gets(s);
     sscanf(s,"%c%c %d %c " ,&ch1, &ch2 , &m, &ch3);
      //printf("%c %c %d %c\n",ch1, ch2, m, ch3);
      if(ch3 == 'Y')
      {
          if(ch1 == '>' && ch2 == '=')
            gr.insert(m-1);
          else if(ch1 == '<' && ch2 == '=')
            sm.insert(m+1);
          else if(ch1 =='>')
            gr.insert(m);
          else
            sm.insert(m);
      }
      else
      {
          if(ch1 == '>' && ch2 == '=')
            sm.insert(m);
          else if(ch1 == '<' && ch2 == '=')
            gr.insert(m);
          else if(ch1 =='>')
            sm.insert(m+1);
          else
            gr.insert(m-1);

      }
    }
    if(gr.empty())
        printf("%d", *sm.begin()-1);
    else if(sm.empty())
        printf("%d", *gr.rbegin()+1);
    else if(*gr.rbegin() >=  *sm.begin() || abs(*gr.rbegin() -  *sm.begin()) <= 1)
        puts("Impossible");
    else
        printf("%d\n" ,*gr.rbegin() + 1);

   // printf("%c %c %d %c\n",ch1, ch2, n, ch3);

    return 0;
}

