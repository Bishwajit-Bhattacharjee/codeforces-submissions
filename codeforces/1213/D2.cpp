#include <bits/stdc++.h>
using namespace std;

double INF = 1e100;
double EPS = 1e-12;
typedef long long int ll;
int const N = 2e5 + 10;
vector < int > v[N] ;

void do_it(int n)
{
    int cnt = 0;
    do{
        v[n].push_back(cnt);
        cnt++, n /= 2;
    }while(n);
    if(n == 0) {
        v[0].push_back(cnt);
    }
}
int main(){

	ios::sync_with_stdio(false); cin.tie(0);

	int n,k;
	cin >> n >> k;

	for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        do_it(tmp);
	}

	for(int i = 0; i < N; i++) sort(v[i].begin(), v[i].end());

	ll ans = 1e12;

	for(int i = 0; i < N; i++){
        ll can = 0;
        if(v[i].size() >= k){
            for(int x = 0; x < k; x++){
                can += v[i][x] ;
            }
        }
        else {
            can = 1e12;
        }
        ans = min(ans,can);
	}
	cout << ans << endl;
    return 0;
}
