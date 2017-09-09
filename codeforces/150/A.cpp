#include <bits/stdc++.h>
using namespace std ;
typedef long long int ll;
ll const MX = (int)1e7 ;

bool mark[(int)MX] ;
vector < ll > prime ;

void sieve()
{
    //prime.push_back(2) ;
    ll lim = sqrt(MX) +  2 ;
     for(ll i = 2; i <= lim ; i++){
        if(!mark[i]){

           for(ll j = i * i ; j <=  MX ; j += i){
               mark[j ] = 1 ;

           }
         //  prime.push_back(i) ;

        }

     }
     for(int i = 2; i <= MX ; i++){
         if(!mark[i])prime.push_back(i);
     }
}


int main()
{
    sieve() ;
    
    ll q ;
    cin >> q ; 
    int cnt = 0;
    ll tmp  = -1;
    ll divi = q ;
//    cout << prime[prime.size() - 1] << endl;
    
     // cout <<"wk" << binary_search(prime.begin() , prime.end() , 1902037 ) << endl;
    if(q < MX  && !mark[q]){
        printf("1\n0") ;
        return 0;
    }
   //cout <<  (   find(prime.begin() , prime.end() , 1902037 ) - prime.begin() ) == prime.size() << endl;
  
    for(auto x : prime ){
        if(divi % x == 0){
            tmp =  x  ,divi = q / x ,  cnt++ ;
            break ;
        }    
       
    }

    ll tmp1 = -1 ;
    for(auto x : prime){
        if(divi % x == 0){
            tmp1 = x ;
            
            cnt++;
            
            break;
        }
    }
     //   cout << "tmp1" << tmp1 << endl;
  //  cout << cnt << endl;
    if(cnt == 0){
       printf("1\n0") ;
       return 0;
    }
    if(cnt == 1){
        cout << "2" << endl;
    }
    if(cnt == 2){
        if(tmp1 * tmp == q ){
            puts("2") ;
            return 0;
        }
        else {
            cout << "1" << endl << tmp1 * tmp  << endl;
        }
    }
   
    return 0;

}
