#include <bits/stdc++.h>
using namespace std;
string s;
int n;

int dp[110][60][210][3];

int DP(int id,int chg,int dist,bool dir)
{
    if(chg > n) return INT_MIN;

    if(id == s.size()) {
        if((n-chg)>=0 and !( (n-chg) & 1) ){
            return abs(dist);
        }
        return INT_MIN;
    }
    int &ret = dp[id][chg][dist+100][dir];
    if(ret != -1) return ret ;
    ret = INT_MIN;

    if(s[id] =='T'){
        ret = max(ret,DP(id+1,chg,dist,!dir)) ;
        ret = max(ret,DP(id+1,chg+1,dist+( (dir)? 1: -1), dir)) ;
    }

    else {
        ret = max(ret,DP(id+1,chg,dist+( (dir)? 1: -1),dir)) ;
        ret = max(ret,DP(id+1,chg+1,dist, !dir)) ;

    }
    return ret;

}
int main()
{
    memset(dp,-1,sizeof dp);
    cin >> s >> n ;
  //  cout << s.size() << endl;
    cout << DP(0,0,0,1) << endl;
    return 0;

}
