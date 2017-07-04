#include <bits/stdc++.h>
using namespace std;
string s;

void f(int i)
{
    if(i == s.size()) return ;
    if(s[i] == 'r'){
        printf("%d\n", i + 1);
         f(i + 1);
    }
    else {
        f(i + 1);
        printf("%d\n", i + 1);
    }
}
int main()
{
 cin >> s;
 f(0);
   return 0;
}