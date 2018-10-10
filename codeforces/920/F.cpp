/// HK 108 Times
#include <bits/stdc++.h>
using namespace std ;
#define ll long long
#define pb push_back
typedef pair <int,int>  PII ;
typedef pair < ll, ll > PLL ;
#define all(x) (x).begin() , (x).end()
#define FAST ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define MOD 1000000007
#define endl '\n'

int const MX = 1e6 + 10;
ll divi[MX] ;
int const SZ = 3e5 + 10;
ll cunt[SZ] ;
ll tr[SZ];
ll ara[SZ] ;

void update(int x,ll val)
{
    for(int i = x; i < SZ; i += (i & -i)){
        tr[i] += val;
    }
}
ll query(int x)
{
    ll sum = 0;
    for(int i = x; i > 0 ; i -= (i & -i))
        sum += tr[i] ;
    return sum;
}

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("in.txt","r",stdin);
       //freopen("out.txt","w",stdout);
       
    #endif
       
    FAST;
    
    for(int i = 1; i < MX; i++){
        for(int j = i; j < MX; j += i)
            divi[j]++;
    }
    //divi[1]++;

    int n,m;
    cin >> n >> m;

    //vector < int > cumOne(n+1,0);
    for(int i = 1; i <= n; i++)
        cin >> ara[i];
    
    for(int i = 1; i <= n;i++)
        update(i,ara[i]);

    set < int > active;

    for(int i = 1; i <= n; i++)
        active.insert(i);

    while(m--)
    {
        int type,l,r;
        cin >> type >> l >> r;
        if(type == 1){
            auto it1 = active.lower_bound(l);
            auto it2 = active.upper_bound(r);

            for(auto it = it1; it != it2;)
            {
                if(cunt[*it] > 6 )
                    it = active.erase(it);
                else {
                    cunt[*it]++;
                    ll val = query(*it) - query((*it) - 1);
                    update(*it,divi[val] - val) ;
                    it++;
                }
            }

        }
        else {
            ll can = query(r) - query(l-1);
            cout << can << endl;
        }
    }
    return 0;
}