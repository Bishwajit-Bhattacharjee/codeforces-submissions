#include<bits/stdc++.h>
using namespace std;
using ll = long long int;


const int block_size = 320; 

struct Query
{
    int l, r, id;
    Query(){}
    Query(int ll, int rr, int _id):l(ll), r(rr), id(_id){

    }
    bool operator<(Query other) const
    {
        return make_pair(l / block_size, r) <
               make_pair(other.l / block_size, other.r);
    }
};

int const N = 1e6 + 10;

int l = 0, r = -1;
ll cnt[N];
vector<Query>Q;
ll ara[N];
ll ans = 0;


void add(int x){

    ans += 2 * cnt[ara[x]] * ara[x] + ara[x];
    cnt[ara[x]]++;
}

void remove(int x){

    ans -= 2 * cnt[ara[x]] * ara[x] - ara[x];
    cnt[ara[x]]--;
}

ll get_ans(){
    return ans;
}

int main()
{
    int n, t;
    cin >> n >> t;

    for (int i = 0; i < n; i++) cin >> ara[i];

    Q.resize(t);
    vector<ll> ans(t);

    for (int i = 0; i < t; i++){
        int l, r;
        cin >> l >> r;
        l--, r--;
        Q[i] = Query(l, r, i);
    }

    sort(Q.begin(), Q.end());


    for (auto q: Q)
    {
        while (l > q.l)
            add(--l);
        while (r < q.r)
            add(++r);
        while (l < q.l)
            remove(l++);
        while (r > q.r)
            remove(r--);
        ans[q.id] = get_ans();
    }

    for (auto x : ans) cout << x << "\n";
    return 0;
}
