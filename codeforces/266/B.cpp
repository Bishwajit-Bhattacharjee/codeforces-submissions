//#inlcude <stdio.h>
#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n, t, i;
    char buf[10], str[100], temp;
    scanf("%d %d ", &n, &t);

   // gets(buf);
    gets(str);
    for(int i = 0; i < t; i++)
    {
        for(int j = 0;j < n; j++)
        {
            if(str[j] == 'B'&& str[j+1] == 'G')
            {
               str[j] = 'G';
            //  str[j] = str[j+1];
              str[j+1] = 'B';
              j++;
            }
        }
    }
    puts(str);
    return 0;

}
