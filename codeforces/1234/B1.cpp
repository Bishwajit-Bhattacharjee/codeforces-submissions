#include <bits/stdc++.h>
using namespace std;
#define lc(l) 2(l)
#define rc(l) 2(l) + 1
typedef long long int ll;
int const N = 2e5 + 20;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
	
	deque < int > dq;
	set < int > st;

	int n,k;
	cin >> n >> k;

	for(int i = 0; i < n; i++) {
		int id;
		cin >> id;
		if(st.find(id) != st.end()){
			continue;
		}
		st.insert(id);
		if(dq.size() == k) {
			
			st.erase(st.find(dq.back()));
			dq.pop_back();
		}
		dq.push_front(id);
		
	}

	cout << dq.size() << endl;

	while(!dq.empty()){
		cout << dq.front() << " ";
		dq.pop_front();
	}
	
    return 0;
}
