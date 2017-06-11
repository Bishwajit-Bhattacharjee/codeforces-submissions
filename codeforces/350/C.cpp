#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-9;
const int INF = (int)(1e9 + 0.5);
const ll MAXN = 100005;

struct point {
	ll x, y, dist;
} mass[MAXN];

bool cmp(const point & a, const point & b) {
	return a.dist < b.dist;
}

int main()
{
	int n,d=0;
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%I64d%I64d", &mass[i].x, &mass[i].y);
		mass[i].dist = mass[i].x * mass[i].x + mass[i].y * mass[i].y;
	}
	sort(mass,mass+n,&cmp);
	for(int i = 0; i < n; ++i) {
		if(mass[i].x != 0) ++d;
		if(mass[i].y != 0) ++d;
		++d;
		if(mass[i].x != 0) ++d;
		if(mass[i].y != 0) ++d;
		++d;
	}
	printf("%d\n", d);
	for(int i = 0; i < n; ++i) {
		if(mass[i].x != 0)
			mass[i].x < 0 ? printf("1 %d L\n", abs(mass[i].x)) : printf("1 %d R\n", abs(mass[i].x));
		if(mass[i].y != 0)
			mass[i].y < 0 ? printf("1 %d D\n", abs(mass[i].y)) : printf("1 %d U\n", abs(mass[i].y));
		mass[i].x *= -1;
		mass[i].y *= -1;
		printf("2\n");
		if(mass[i].x != 0)
			mass[i].x < 0 ? printf("1 %d L\n", abs(mass[i].x)) : printf("1 %d R\n", abs(mass[i].x));
		if(mass[i].y != 0)
			mass[i].y < 0 ? printf("1 %d D\n", abs(mass[i].y)) : printf("1 %d U\n", abs(mass[i].y));
		printf("3\n");
	}
	return 0;
}