//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    char str[110];
    char h[] = "hello";
    gets(str);
    int h_i = 0, count = 0;
    for(int str_i = 0;str_i < strlen(str); str_i++)
    {
        if(str[str_i] == h[h_i])
        {
            count++;
            h_i++;
        }
    }
    if(count == 5)
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
