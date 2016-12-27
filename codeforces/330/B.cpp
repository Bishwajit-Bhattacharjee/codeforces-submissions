//#pragma comment(linker, "/STACK:16777216")
//#include<iostream>
#include<cstdio>
//#include<cmath>
//#include<algorithm>
#include<vector> 
#include<cstring>
#include<string>
//#include<queue>
#define mp make_pair
#define scn second
#define frs first
#define pb push_back
#define NAME "a"
#define fop freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout); 
using namespace std;
const unsigned long long P=239017, MaxN=2100000, INF=100000000;
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pi;

int n, m, d[10010];

int main(){
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; ++i) {
		int a, b;
		scanf("%d%d", &a, &b);
		++d[a], ++d[b];
	}
	int st = 0;
	for (int i = 1; i <= n; ++i) {
		if (d[i] == 0)
			st = i;	
	}
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; ++i) {
		if (i == st)
			continue;
		printf("%d %d\n", st, i);
	}
	return 0;
}