#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin() , (x).end()
int const MX = 3e5 + 10;
vector < string > per;

void pre()
{
    string temp = "1689";
    do{
        per.pb(temp);
    }while(next_permutation(all(temp)));
} 
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    pre();


    string s;
    cin >> s;
    string bam, dan;
    int cnt[12];
    memset(cnt,0,sizeof cnt);

    for(auto x: s)
    {
        if(x == '0') dan += x;
        else if(x == '1' or x == '6' or x == '8' or x == '9'){
            cnt[x-'0']++;
            if(cnt[x-'0']>=2 )
            {
                bam += x;
            }
        }
        else 
            bam += x;
    }

    for(int i = 0; i < per.size(); i++)
    {
        int mod = 0;
        int pow = 1;
        string tmp = "";
        tmp += dan;
        tmp += per[i] ;
        tmp += bam;

        for(auto x : tmp){
            mod += (pow * (x-'0'));
            mod %= 7;
            pow = (pow * 10 ) % 7;
        }
        
        if(mod == 0 ) {
            reverse(all(tmp));
            return cout << tmp << endl, 0;
        }
    }
    return 0 ;
}