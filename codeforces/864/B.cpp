#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 1e3 + 10 ;
ll const MOD =  1000000007  ;

int main()
{
    int n ;
    string s ;
    //cin >> n ;
    while(cin >> n >> s  ){
        set <  char > st ;
        int ans = 0;
        int tmp =0 ;
        for(int i = 0 ; i < s.size(); i++){
            if(s[i] >= 'A' and s[i] <= 'Z'){
                ans = max(ans ,(int) st.size() ) ;
               // tmp = 0;
                st.clear() ;
            }
            else {
                st.insert(s[i]) ;
            }
        }
        if(s.size() ){
            ans = max(ans ,(int) st.size()) ;
        }

        cout << ans << endl;
    }
    return 0;
}
