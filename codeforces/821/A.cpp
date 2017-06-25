#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, a[55][55];
	cin >> n;
	for(int i = 0; i < n; i++){
		for(int j =0 ; j < n; j++)scanf("%d", &a[i][j]);
	}
	int f = 1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(a[i][j] != 1){
				int tmp = 0;
				for(int k = 0 ; k < n; k++){
					for(int l = 0; l < n; l++){
						if(a[i][j] == a[i][k] + a[l][j])
						  tmp = 1;
					}
				}
				if(!tmp){f = 0; break;}
			}
		}
	}
	(f)?puts("YES"): puts("NO");
	// your code goes here
	return 0;
}