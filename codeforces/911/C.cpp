#include <bits/stdc++.h>
using namespace std;

int main()
{
    int cnt[1510] ;
    memset(cnt , 0 ,sizeof cnt) ;
    int a;
    for(int i =0 ; i < 3 ; i++)
    {
        cin >> a ;
        cnt[a-0]++;
    }
    bool f = false ;
    if(cnt[1])
        f = true ;
    else if(cnt[2] >= 2 )
        f = true;
    else if(cnt[2] == 1 && cnt[4] == 2)
        f = true ;
    else if(cnt[3] == 3)
        f = true;
    else
        f = false;
    printf("%s",f?"YES":"NO") ;


    return 0;
}
