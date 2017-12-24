#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(false)
#define endl '\n'
int ara[1010] ;
int main()
{
   // FAST ;
    int n , m , c ;
    cin >> n >> m >> c ;
    memset(ara, -1, sizeof ara) ;
    for(int j = 1; j <= m ; j++){
        int tmp ;
        int out = -1;
        cin >> tmp ;
        if(tmp  > c/2 ){
            for(int i = n; i >= 1; i--){
                if(ara[i] == -1){
                    out = i ; break;
                }
                if(ara[i] < tmp ) {
                    out = i ; break;
                }

            }
            if(out == -1) out = 1;
        }
        else {
            for(int i = 1;i <= n ; i++){
                if(ara[i] == -1){
                    out = i ; break;
                }
                if(ara[i] > tmp) {
                    out = i  ; break;
                }

            }
            if(out == -1) out = n;
        }
        ara[out] = tmp ;
        cout << out << endl;

//        //
//        for(int i =1; i <= n ;i++)
//            cout << ara[i] << ' ';
//        cout << endl;
//        //

        cout.flush();
        int valid = 0, minusCount = (ara[1] == -1);
        for(int i = 2; i <= n;i++){
            if(ara[i] >= ara[i-1]) valid++ ;
            if(ara[i] == -1) minusCount++;
        }
        if(!minusCount && valid == n - 1 ) {
            return 0;
        }
    }
    return 0;
}
