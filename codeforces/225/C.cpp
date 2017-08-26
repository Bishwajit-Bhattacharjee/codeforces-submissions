#include <bits/stdc++.h>

using namespace std;
int need[1010][3] ;

string grid[1010] ;
int n, m, x ,  y ;
int dp[1010][3] ;    

int DP(int whr , int flg )
{
    if(whr == m)
      return 0;
    
    int &ret = dp[whr][flg] ;
    
    if(ret != -1)
        return ret ;
    
    ret = 1<<29 ;
    int i , j ;
      for(i=whr+x-1,j= x-1; i < m && j < y ;i++,j++){
        ret = min( ret, need[i][flg]  - ( (whr == 0)? 0: need[whr-1][flg]) + DP(i + 1 , flg ^ 1 ) );
        //cout << whr <<' ' <<  flg << ' ' << ret << endl;
    }
    
    return ret ;
    
}


int main()
{
    memset(need, 0 , sizeof need ) ;
    
  
    
    cin >> n >>  m >>  x  >>  y ;
    
    for(int i = 0 ; i <  n  ; i++ ){
        cin >> grid[i] ;
        
    }
    
    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n; j++){
            need[i][0] += (grid[j][i] == '.') ;
        }
        need[i][1] = n - need[i][0] ;
    }
    
    for(int i = 1 ; i < m ; i++){
        need[i][0] += need[i-1][0] ;
        need[i][1] += need[i-1][1] ;
    }
 
    memset(dp , -1 , sizeof dp ) ;
    
    cout << min(DP(0 , 0 ) , DP( 0 , 1 ) ) << endl;
    
     
}