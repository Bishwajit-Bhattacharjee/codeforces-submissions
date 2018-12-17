#include <bits/stdc++.h>
using namespace std;
int const BLOCK_SIZE = sqrt(10 + 2e5 ) + 1;
typedef long long int ll;

struct Q
{
    int l,r,id;
    Q(){}
    Q(int a,int b,int c):l(a),r(b),id(c){
    }
    bool operator<(Q &rhs)
    {
        int b_1 = l / BLOCK_SIZE ;
        int b_2 = rhs.l / BLOCK_SIZE;
        if(b_1 == b_2)
            return r < rhs.r;
        return b_1 < b_2;
    }
};
int const MX = 1e6 + 10;
ll mp[MX] ;
ll cnt;
ll ara[MX];

ll get_ans()
{
    return cnt;
}

void add(int l)
{
    l = ara[l] ;
    cnt -= mp[l]* mp[l] * l;
    mp[l]++;
    cnt += mp[l]* mp[l] * l;
    //mp[l]++;
}
void del(int l)
{
    l = ara[l] ;
    cnt -= mp[l]* mp[l]*l;
    mp[l]--;
    cnt += mp[l]* mp[l] * l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;

    for(int i = 0; i < n; i++)
        cin >> ara[i];
    int curL = 0, curR = -1;


    vector < Q > prosno(q);
    vector < ll > ans(q);

    for(int i = 0; i < q; i++)
    {
        int l,r;
        cin >> l >> r;
        prosno[i] = Q(l-1,r-1,i);
    }
    sort(prosno.begin(), prosno.end());

    for(Q q : prosno)
    {
        while(curL < q.l){
            del(curL++);
        }
        while(curL > q.l)
        {
            add(--curL);
        }
        while(curR < q.r)
        {
            add(++curR);
        }
        while(curR > q.r){
            del(curR--);
        }
        ans[q.id] = get_ans();
    }
    for(int i = 0; i < q; i++)
        cout << ans[i] << '\n';

    return 0;
}
