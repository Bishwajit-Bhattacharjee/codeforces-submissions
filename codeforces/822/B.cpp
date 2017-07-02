#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
int main()
{
    string s1 , s2 ;
    int l1 , l2; cin >> l1 >> l2; cin >> s1 >> s2;
            int ans = INT_MAX, id = -1;

    for(int i = 0; i <=  l2 - l1 ; i++){
        int c = 0;
        string s = s2.substr(i , l1);
        for(int j = 0; j < l1 ; j++){
            if(s[j] != s1[j]) c++;
        }
        if(ans  > c){
            ans = c, id = i;
        } 
    }
    cout << ans << endl;
    //for(int i = 0 )
   string  s = s2.substr(id , l1) ; 
    for(int i = 0 ; i < l1; i++){
        if(s[i] != s1[i])
        printf("%d ",  1 + i);
    }
    return 0;
}