#include <bits/stdc++.h>

using namespace std;

int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	int ar[70];
	for(int i=0;i<n;i++) scanf("%d",&ar[i]);
	sort(ar,ar+n);
	reverse(ar,ar+n);
	int start = k;
	int ct = 0;
	for(int i=0;i<n;i++){
		if(start >= m) break;
		start += (ar[i] - 1);
		++ct;
	}
	if(start < m) ct = -1;
	cout << ct << endl;
	return 0;
}