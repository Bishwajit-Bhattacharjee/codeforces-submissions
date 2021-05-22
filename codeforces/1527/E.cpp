#include <bits/stdc++.h>
using namespace std;
 
#define L(x) (x)<<1
#define R(x) (x)<<1|1
 
using ll = long long int;
 
ll const IDENTITY = 1e13; //  change

struct Node{    // change
    int type; // 1 -> inc, 2 -> set
    ll val;

    Node(){
        type = 1, val = 0;
    }
    Node(int t, ll v):type(t), val(v){}
};
 
int const N = 2e5 + 10;
ll t[4*N]; 
ll dp[N];

Node lazy[4*N];

 
ll merge(ll l, ll r){ // change
	return min(l, r);
}

/**
 * Given the lazy in the node, and a new operation,
 * update the lazy value.
 **/
void assignOp(int p, Node op) {  // change

	lazy[p].val += op.val;
}
/**
 *  Given the lazy in for a node, calculate its value,
 *  and push the lazy down to the childs
 **/

void push(int p, int l, int r){  // change

    if (lazy[p].val){
        // assert(lazy[p].size() <= 1);

        auto last = lazy[p];

        if (l != r){

            for (auto ch : {L(p), R(p)}){
                assignOp(ch, last);
            }
        }
        ll add = last.val;
        t[p] += add;
    }
    lazy[p] = Node();
}
 
void build(int p, int l, int r){
	lazy[p] = Node();
    if (l == r) {
        t[p] = dp[l]; return;
    }
    int mid = (l+r)/2;
    build(L(p), l, mid);
    build(R(p), mid+1, r);
 
    t[p] = merge(t[L(p)], t[R(p)]);
}
 
 
void update(int p, int l, int r, int ul, int ur, Node op){
    
    push(p, l, r); // The order matters

    if (l > ur || r < ul) return;
 
    if (ul <= l && r <= ur) {
        
        assignOp(p, op);
        push(p, l, r);
        return;
    }
 
    int mid = (l+r)/2;
    update(L(p), l, mid, ul, ur, op);
    update(R(p), mid+1, r, ul, ur, op);
 
    t[p] = merge(t[L(p)], t[R(p)]);
}
 
ll Q(int p, int l, int r, int ql, int qr){
    push(p, l, r); // The order matters

    if (l > qr || r < ql) return IDENTITY;
    
    if (ql <= l && r <= qr) return t[p];
 
    int mid = (l+r)/2;
 
    return merge(
        Q(L(p), l, mid, ql, qr),
        Q(R(p), mid+1, r, ql, qr)
    );
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);

	int n, k;
	cin >> n >> k;
	vector<int> a(n+1), last(n+1, -1);

	for (int i = 1; i <= n; i++){
		cin >> a[i];
		dp[i] = dp[i-1];
		if (last[a[i]] != -1) dp[i] += (i - last[a[i]]);
		last[a[i]] = i;
	}


	// cout << "Initial " << endl;

	// for (int i = 1; i <= n; i++) cout << i << " " << dp[i] << endl;


	for (int cut = 1; cut < k; cut++){
		fill(last.begin(), last.end(), -1);
		build(1, 1, n);

		// cout << "Cut " << cut << endl;

		for (int i = 1; i <= n; i++){
			
			if (last[a[i]] > 1) 
				update(1, 1, n, 1, last[a[i]] - 1, Node(1,i - last[a[i]]));


			// cout << "current Ind : " << i <<  endl;

			// for (int j = 1; j <= i; j++){
			// 	cout << Q(1, 1, n, j, j) << " ";
			// }
			// cout << endl;

			last[a[i]] = i;			
			if (i > 1 ) dp[i] = Q(1, 1, n, 1, i-1);
			else dp[i] = IDENTITY;

			// cout <<"final "<< i << " " << Q(1, 1, n, i, i) << " " << dp[i] <<  endl;
		}
	}

	cout << dp[n] << endl;
    return 0;
}