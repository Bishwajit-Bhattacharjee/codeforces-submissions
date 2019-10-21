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
	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		update(i+1,s[i]-'a',1);
	}

	int q;
	cin >> q;
	
	while(q--){
		int t;
		cin >> t;
		if(t == 1){
			int pos; char ch;
			cin >> pos >> ch;
			update(pos,s[pos-1]-'a',-1);	
			s[pos-1] = ch;	
			update(pos,ch-'a',1);		
		}
		else {
			int cnt = 0;
			int l,r;
			cin >> l >> r;
			for(int i = 0; i < 26; i++){
				cnt += ((Q(r,i) - Q(l-1,i)) > 0 );
			}
			cout << cnt << endl;
		}
	}
    return 0;
}
