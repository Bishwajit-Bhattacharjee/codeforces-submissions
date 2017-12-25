#include <bits/stdc++.h>
using namespace std ;
const int MX = 1e5 + 10;
long long ara[MX] ;
long long csum[MX] ;
int main()
{
    char str[1010] ;
    scanf("%s",str) ;
    int cnt[30] ;
    memset(cnt ,0 ,sizeof cnt) ;
    for(int i = 0; i < strlen(str); i++){
        cnt[str[i] - 'a']++ ;
    }
    int cc = 0;
    for(int i = 0 ; i < 27; i++){
        cc += ( cnt[i] > 0 ) ; 
    }
    if(!(cc & 1) ) {
        puts("CHAT WITH HER!") ;
    }
    else {
        puts("IGNORE HIM!");
    }
    return 0;
}
