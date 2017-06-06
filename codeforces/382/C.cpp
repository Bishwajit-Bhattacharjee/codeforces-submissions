// HK  HK HK HK HK HK   JSN  JRR

#include <bits/stdc++.h>
#define PII pair < int , int >
#define PIB pair < int , bool >
#define PI 2.0*acos(0.0)
#define ll long long int
#define FOR(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceiling(a, b) (a %b == 0)?(a/b):(a/b)+1
#define F first
#define S second
#define lu unsigned long long int
int const up =   1e6 + 10 ;
int const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const MX =   5 *1e5 + 10;
int const mod = 1e9 + 7;

using namespace std;
int main()
{
    int a[MX] ;
    int n;
    cin >> n;
    for(int i = 0; i< n; i++)
        scanf("%d", &a[i]);
    set < int > s;
    sort(a, a + n);
    for(int i = 0 ; i < n-1 ; i++){
       s.insert(a[i+1]-a[i]);
    }
    if(n == 1){
        puts("-1");
        return 0;
    }
    if(s.size() == 1 && *s.begin() == 0){
        printf("1\n%d", a[0]);
        return 0;
    }
    if(s.size() > 2 || s.size() == 0)
    {
        puts("0");
    }
    else if(s.size() == 1 && n >= 3) {
         printf("2\n%d %d", a[0]-*s.begin(), a[n-1] + *s.begin());
    }
    else if(s.size() == 1 && n==2){
        if(*s.begin() > 0){
            if((a[0] + a[1]) % 2 == 0)
            printf("3\n%d %d %d", a[0] - *s.begin(), (a[0] + a[1])/2 , a[1] + *s.begin());
            else{
                printf("2\n%d %d", a[0] - *s.begin(), a[1] + *s.begin())   ;
            }
        }
        else  {
            puts("0");
        }
    }
    else if(s.size() == 1){
        printf("2\n%d %d",  a[0] - *s.begin(), a[1] + *s.begin());
    }
    else if(s.size() == 2){
         auto it = s.begin();
         it++;
         int t = *it;
         if(t % 2){
            puts("0");
         }
         else{
                int t1 = *s.begin();
            int cnt = 0, tmp = -1;
            if(t1 * 2 != t){
                puts("0");
                return 0;
            }
            for(int i =0; i< n-1; i++){
              if(a[i+1] - a[i] == t){
                 cnt++;
                 if((a[i] + a[i+1]) % 2 == 0){
                    tmp = (a[i] + a[i+1])/2 ;
                }

              }

            }
            if(cnt == 1 && tmp != -1){
                printf("1\n%d", tmp);
            }
            else {
                 puts("0");
            }
         }
    }
    else
        puts("0") ;

     return 0;
}
