#include <bits/stdc++.h>
using namespace std ;
#define ll long long
int const MX = 1e5 * 3  + 10 ;
#define pb push_back
typedef pair <int,int>  PII ;
vector < PII > given ;
vector < pair < int , PII >  >  edge  ;
vector < PII > one , two ;
#define F first
#define S second

bool endswith(string s1, string s2){
  if(s1.size() >= s2.size()){
    int diff = s1.size() - s2.size() ;
    for(int i = 0 ; i < s2.size() ; i++){
        if(s1[diff + i] != s2[i])
            return 0 ;
    }
    return 1;
  }
  return 0 ;
}

int main()
{
//    freopen("in.txt","r",stdin) ;
//    freopen("out.txt","w",stdout) ;
    ios_base::sync_with_stdio(false) ;

    int n, k , m , t ;
    while(cin >> n >> m >> k ) {
       vector < int > s(n), dead(n, 0) ;
       for(int i = 0; i < n ; i++){
           cin >> s[i] ;
       }
       sort(s.begin(), s.end()) ;
       int lft, rgt ;
       int cnt = 1;
       int ans = 0;
       for(lft = 0, rgt = 0 ; lft < n && rgt < n ; ){
          while(s[rgt] - s[lft] >= m && (rgt >= lft)){
             cnt -= !dead[lft++] ;
          }
          while(rgt < n && s[rgt] - s[lft] < m ) {
                //cnt++ ;
                if(cnt >=  k) {
                    dead[rgt] = 1; ans++;
                    cnt--;
                }
                rgt++, cnt++;
          }
       }
       cout << ans << endl;
//       for(int i = 0 ;i < n ; i++) {
//            cout << dead[i] << " " ;
//       }
    }
    return 0 ;
}
