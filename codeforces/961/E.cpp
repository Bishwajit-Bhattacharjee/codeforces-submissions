#include <bits/stdc++.h>
using namespace std;

int const N = 2e5 + 10;
typedef long long int ll;
ll tree[N] ;

void update(int n,int val)
{
    while(n < N )
    {
        tree[n] += val, n += (n & -n);
    }
}
ll Q(int n)
{
    ll ans = 0;
    while(n)
    {
        ans += tree[n], n -= (n & -n) ;
    }
    return ans;
}
typedef pair < int, int > PII;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector < int > ara(n+1);
    set < PII > st;

    for(int i = 1; i <= n; i++)
    {
        cin >> ara[i] , update(i,1);
        ara[i] = min(n,ara[i]) ;
        //st.insert({ara[i],i});
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {

        for(auto it = st.begin(); it != st.end(); )
        {
            if((*it).first < i ) {
                update((*it).second, -1);
                it = st.erase(it);
            }
            else
                break;
        }
        int can = min(i-1,ara[i]);
        if(can != 0)
        {
            ans += Q(can);
        }
        st.insert({ara[i],i});
    }
    cout << ans << endl;

}
