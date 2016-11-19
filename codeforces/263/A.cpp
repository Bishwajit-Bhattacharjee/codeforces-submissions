//#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int ara[5][5];
    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            scanf("%d",&ara[i][j]);
    }
    int r , c;

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 5; j++)
            {
                if(ara[i][j] == 1)
                {
                    r = i; c = j;
                }
            }
    }

    printf("%d\n", abs(2-r)+ abs(2-c));

    return 0;
}
