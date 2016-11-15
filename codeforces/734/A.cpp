#include <bits/stdc++.h>
#include <stdio.h>

using namespace std;
int main()
{
        char str[100009], buf[12];
      int n;
        scanf("%d", &n);
          gets(buf);
          gets(str);
        int a_c =0,  d_c = 0,i;
        for( i = 0; i < n;i++)
        {
            if(str[i] == 'A')
                a_c++;
            else if(str[i] == 'D')
                d_c++;
        }
        if(a_c > d_c)
            printf("Anton\n");
        else if(a_c < d_c)
            printf("Danik\n");
        else
            printf("Friendship\n");
    return 0;
}
