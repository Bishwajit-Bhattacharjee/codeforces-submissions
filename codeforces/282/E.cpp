#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

struct node
{
    node* next[2];
    int cnt[2];
    node(){
        for(int i = 0; i < 2; i++)
            next[i] = NULL, cnt[i] = 0;

    }
};

node* root;

void insert(vector <int> v)
{
    node* now = root;

    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(!(now->next[v[i]])){
            node* tmp = new node();
            now->next[v[i]] = tmp;
        }
        now->cnt[v[i]]++;
        now = now->next[v[i]];
    }
}

void erase(vector <int> v)
{
    node* now = root;

    for(int i = v.size() - 1; i >= 0; i--)
    {
        now->cnt[v[i]]--;
        now = now->next[v[i]];
    }
}

ll max_xor(vector < int > v)
{
    node* now = root;

    ll ret = 0;

    for(int i = v.size() - 1; i >= 0; i--)
    {
        if(now->next[v[i]^1] and now->cnt[v[i]^1])
        {
            ret |= (1LL<<i);
            now = now->next[v[i]^1];
        }
        else {
            now = now->next[v[i]];
        }
    }

    return ret;
}
vector < int > bitify(ll num)
{
    vector < int > v;
    if(!num)
        v.push_back(0);
    else {
        while(num){
            v.push_back(num % 2);
            num /= 2;
        }
    }
    while(v.size() < 40)
        v.push_back(0);
    return v;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    root = new node();
    int n;
    cin >> n;
    vector < ll > a(n+1,0),suff(n+2,0);

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    insert(bitify(0));
    for(int i = n; i >= 1; i--)
        suff[i] = suff[i+1] xor a[i] , insert(bitify(suff[i]));

    ll so_far = 0;
    ll ans = max_xor(bitify(0));
    for(int i = 1; i <= n; i++)
    {
        erase(bitify(suff[i]));
//        if(i!=1){
//            erase(bitify(so_far));
//        }
        ll tmp = max_xor(bitify(so_far ^ a[i]));
        ans = max(tmp,ans);
        so_far = so_far ^ a[i] ;

        //insert(bitify(so_far = so_far^a[i]));
    }
    cout << ans << endl;
    return 0;
}
