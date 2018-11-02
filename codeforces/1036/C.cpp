#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
vector < ll > lucky;

void pre(int pos,int cnt,ll num)
{
    if(pos == 18 ) {
        if(num)lucky.push_back(num);
        return ;
    }
    if(cnt < 3)
    {
        for(int i = 1; i <= 9; i++)
            pre(pos+1,cnt+1,num*10 + i );
    }
    pre(pos+1,cnt, num*10 );
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    pre(0,0,0);
    lucky.push_back(1000000000000000000LL);
    sort(lucky.begin(),lucky.end());
    //cout << lucky.size() << endl;
    //cout << lucky.back() << endl;
    //cout << lucky.size() << endl;
    while(t--)
    {
        ll l, r;
        cin >> l >> r;
        cout << (int)(upper_bound(lucky.begin(),lucky.end(),r) - lower_bound(lucky.begin(),lucky.end(),l)) << '\n';
    }
    return 0;
}
