
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
int const MX = 2e6 + 10;
ll mp[MX];
ll cnt;
ll ara[MX];
ll tmp[MX];
ll k;

ll get_ans()
{
    //cout << cnt << endl;
    return cnt;
}

void add(int l)
{
    l = ara[l] ;
    cnt += mp[k^l] ;
    //cout << "ADD " << cnt << " " << mp[l] << endl;

    mp[l]++;
}
void del(int l)
{
    l = ara[l] ;
    mp[l]--;

    cnt -= mp[k^l];

}
int main()
{
//    ios::sync_with_stdio(false);
//    cin.tie(0);
    int n, qq;
    cin >> n >> qq >> k;

    for(int i = 1; i <= n; i++){
        cin >> tmp[i];
        ara[i] = ara[i-1] ^ tmp[i] ;
        //cout << ara[i] << endl;
    }
    //memset(mp,0,sizeof mp);
    int curL = 0, curR = -1;

    vector < Q > prosno(qq);
    vector < ll > ans(qq);

    for(int i = 0; i < qq; i++)
    {
        int l,r;
        cin >> l >> r;
        prosno[i] = Q(l-1,r,i);
    }
    sort(prosno.begin(), prosno.end());

    for(Q q : prosno)
    {
        while(curL < q.l){
            del(curL++);
            //cout << q.l  << " " << q.id << endl;
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

//        cout << endl;
//        for(int i = 0; i < 2; i++)
//            cout << mp[i] << " " ;
//        cout << endl;
    }
    for(int i = 0; i < qq; i++)
        cout << ans[i] << '\n';

    return 0;
}
/**
5 5 1
1 1 1 1 1
1 1
1 2
1 3
2 3
2 4
**/
