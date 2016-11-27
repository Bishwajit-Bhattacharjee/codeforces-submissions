
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,k;
    scanf("%d %d", &n, &k);
    char buf[10], a[110];
    gets(buf);
    gets(a);
    int i_g , i_t;
    for(int i =0 ; i < n; i++)
    {
            if(a[i]=='G')
                i_g = i;
            else if(a[i] =='T')
                i_t = i;
    }
    int ans = 0;
    if(i_g <= i_t)
    {
        for(int j = i_g; j <= i_t; j+= k)
        {
            if(j >= n)
                break;
             if(a[j] == '#')
                break;
             if(a[j] == 'T')
            {
                ans = 1;
                break;
            }

        }
    }
    else
    {
        for(int j = i_g; j >= i_t; j -= k)
        {
            if(j < 0)
                break;
            if(a[j] =='#')
                break;
            if(a[j] == 'T')
            {
                ans = 1;
                break;
            }
        }
    }
    if(ans)
        printf("YES\n");
    else if(!ans)
        printf("NO\n");


	return 0;
}



