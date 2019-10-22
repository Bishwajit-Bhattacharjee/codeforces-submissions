#include <bits/stdc++.h>
using namespace std;
#define lc(l) 2(l)
#define rc(l) 2(l) + 1
typedef long long int ll;
int const N = 2e5 + 20;

int t[27][N] ;

void update(int id, int c,int val)
{
	while(id < N ){
		t[c][id] += val;
		id += (id & -id);
	}
}
int Q(int id,int c)
{
	if(id == 0) return 0;
	int ans = 0;
	while(id){
		ans += t[c][id] ;
		id -= (id & -id) ;
	}
	return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	int q;
	cin >> q;
	while(q--){
		int cnt = 1;
		int n;
		cin >> n;
		vector < int > v(n);
		
		for(int i = 0; i < n; i++) cin >> v[i];
		sort(v.begin(), v.end());

		for(int i = 1; i < v.size(); i++){
			if(v[i] - v[i-1] == 1) {
				cnt++;
				break;
			}
		}
		cout << cnt << endl;
		
	}
    return 0;
}
