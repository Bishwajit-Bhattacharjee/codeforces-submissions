/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
    #endif
    FAST;
    int n;
    cin >> n;
    map < string, PLL > mp;
    map < string, int > sec;
    vector < string > v(n+1);
    for(int i = 0; i < n; i++)
        cin >> v[i] ;

    for(int i = 0; i < n; i++)
    {
        sec.clear();
        for(int j = 0; j < v[i].size(); j++)
        {
            for(int k = 1; k + j <= v[i].size(); k++){
                string ss = v[i].substr(j,k);
                sec[ss] = 1;
                /*mp[ss].first++;
                mp[ss].second = i;*/
            }
        }
        for(auto x : sec)
        {
            mp[x.first].first++;
            mp[x.first].second = i;
        }
    }

    int q;
    cin >> q;
    while(q--)
    {
        string s;
        cin >> s;
        if(mp.count(s)){
            cout << mp[s].first << " " << v[mp[s].second] << '\n';
        }
        else {
            cout << "0 -" << '\n';
        }
    }
    return 0;
}