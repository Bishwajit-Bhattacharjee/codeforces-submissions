#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a[10] = { 0 };
    char str[100];
    gets(str);
    int len = strlen(str);
    for(int i =0 ; i < len ; i++)
    {
        if(str[i] =='4')
            a[4]++;
        else if(str[i] == '7')
            a[7]++;
    }
    if(a[4] == 0 && a[7] == 0)
        puts("-1");
    else if(a[4] > a[7] || a[4] == a[7])
        puts("4");
    else
        puts("7");
     return 0;
}
