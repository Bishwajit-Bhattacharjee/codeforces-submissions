#include <bits/stdc++.h>
using namespace std;
int const bit = 30;
typedef long long int ll;
struct node
{
    ll cnt,val;
    node* chl[2];
    node(){
        cnt = 0;
        val = 0;
        for(int i = 0; i < 2; i++) chl[i] = nullptr;
    }
};
node* root;

string binary(int num)
{
    string bin = "";
    while(num) {
        bin += (char) ('0'+num%2) ;
        num /= 2;
    }
    while(bin.size() < bit)
        bin += '0';
    reverse(bin.begin(), bin.end());
    return bin;
}

void Insert(ll num)
{
    string s = binary(num);
    node* cur = root;
    for(int i = 0; i < s.size(); i++){
        if(!cur->chl[s[i]-'0']){
            cur->chl[s[i]-'0'] = new node();
        }
        cur = cur->chl[s[i]-'0'];
        cur->cnt++;

    }
}
void Erase(ll num)
{
    string s = binary(num);
    node* cur = root;
    for(int i = 0; i < s.size(); i++){
//        if(!cur->chl[s[i]-'0']){
//            cur->chl[s[i]-'0'] = new node();
//        }
        cur = cur->chl[s[i]-'0'];
        cur->cnt--;
    }
}
void del(node* cur)
{
    if(!cur) return ;
    for(int i = 0; i < 2; i++){
        del(cur->chl[i]) ;
    }
    delete cur;
}
ll Q(ll a, ll b)
{
    string x = binary(a);
    string y = binary(b);
    //ll ans = 0;
    node* cur = root;
    ll ans = 0;
    //bool flag = 0;
    for(int i = 0; i < y.size(); i++)
    {
        if(y[i]-'0'){
            if(x[i]-'0'){
                if(cur->chl[1]){
                    ans += cur->chl[1]->cnt;
                }
                if(cur->chl[0])
                    cur = cur->chl[0] ;
                else
                    return ans;
            }
            else {
                if(cur->chl[0]){
                    ans += cur->chl[0]->cnt;
                }
                if(cur->chl[1])
                    cur = cur->chl[1] ;
                else
                    return ans;
            }
        }
        else {
            if(cur->chl[x[i] - '0']){
                cur = cur->chl[x[i] - '0'];
            }
            else
                return ans;

        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    root = new node();
    int q;
    cin >> q;
    for(int i = 0;i < q; i++)
    {
        int t, tmp ;
        cin >> t >> tmp;
        if(t == 1){
            Insert(tmp);
        }
        else if(t == 2){
            Erase(tmp);
        }
        else {
            int p;
            cin >> p;
            cout << Q(tmp,p) << '\n';
        }
    }
    del(root);
    return 0;
}
