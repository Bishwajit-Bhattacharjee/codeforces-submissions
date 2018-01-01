#include <bits/stdc++.h>
using namespace std;

int ara[1600] ;

int main()
{

    int n ;
    cin >> n ;

    for(int i = 1 ; i <= n; i++)
        scanf("%d",&ara[i]) ;

    int par = 0;

    for(int i = 1; i <= n ;i++)
        for(int j = i + 1; j <= n; j++)
            if(ara[i] > ara[j])
                par++;

    par = par & 1;

    int q;
    cin >> q ;

    while(q--)
    {

        int l , r ;
        scanf("%d %d",&l , &r) ;
        int tmp = (r-l +1 ) >> 1;
        par ^= (tmp & 1) ;
        printf("%s\n",par?"odd":"even") ;

    }
    return 0 ;
}
