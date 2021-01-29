#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace std;
using namespace __gnu_pbds;
int const N = 1010;
string inp[N];

bool check(vector<vector<int>> &a, vector<vector<int>> &b) {

	for (int i = 0; i < a.size(); i++){
		for (int j = 0; j < a[i].size(); j++) {
			if (a[i][j] != b[i][j]) return false;
		}
	}
	return true;
}

void flip_a_row(vector<vector<int>> &a, int r){
	for (int i = 0; i < a[r].size(); i++) a[r][i] ^= 1;
} 
void flip_a_col(vector<vector<int>> &a, int c){
	for (int i = 0; i < a.size(); i++) a[i][c] ^= 1;
}

void do_rest(vector<vector<int>> &a, vector<vector<int>> b){
	int cnt = 0;
	for (int r = 1; r < a.size(); r++){
		cnt = 0;
		for (int c = 0; c < a[r].size(); c++){
			if (a[r][c] ^ b[r][c]) {
				cnt = 1; break;
			}
		}
		if(cnt) flip_a_row(a, r);
	}
}

bool rowFlip(vector<vector<int>> a, vector<vector<int>> b, bool flip) {
	if(flip) flip_a_row(a, 0);
	for (int i = 0; i < a.size(); i++){
		if (a[0][i] != b[0][i]) flip_a_col(a, i);
	}
	do_rest(a, b);	

	return check(a, b);
}

void solve(){
	int n;
	cin >> n;
	vector <vector<int>> a, b;
	a.assign(n, vector<int> (n));
	b.assign(n, vector<int>(n));

	for (int i = 0; i < n; i++){
		cin >> inp[i];

		for (int j = 0; j < n; j++) a[i][j] = inp[i][j] - '0';
	}	

	for (int i = 0; i < n; i++){
		cin >> inp[i]; 

		for (int j = 0; j < n; j++) b[i][j] = inp[i][j] - '0';
	}

	if (rowFlip(a, b, 0) or rowFlip(a, b, 1)) {
		cout << "YES\n";
	}
	else cout << "NO\n";
}

int main(){
	ios::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;

	while(t--) solve();	
	return 0;
}
