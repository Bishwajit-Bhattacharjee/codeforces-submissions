/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int const INF = 10;


int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    
    ll n;
    string s;
    cin >> n;
    
    cin >> s;
    int cnt[26] ;
    memset(cnt,0,sizeof cnt);
    for(auto x : s)
        cnt[x-'a']++;

    string ans = "";

    for(int i =0; i < 26;i++)
        while(cnt[i])
            ans += (char)(i+'a'),cnt[i]--;

    assert(ans.size() == s.size());

    cout << ans << endl;

    return 0;
}