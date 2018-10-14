#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int dig[12];
ll n,b,k,x;
int const MOD = 1e9 + 7;

struct mat
{
	ll a[100+1][100+1];
	mat(){
		for(int i = 0; i < x;i++)
		{
			for(int j =0 ; j < x; j++)
				a[i][j] = (i == j);
		}
	}

	void setter()
	{
		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < x; j++)
			{
				a[i][j] = 0;
				for(int l = 1; l <= 9;l++)
				{
					if((10*j + l) % x == i)
					{
						a[i][j] += dig[l];
					}
				}
			}
		}
	}
	void print(){
		for(int i = 0; i < x; i++)
		{
			for(int j = 0; j < x; j++)
				cout << a[i][j] << " " ;
			cout << '\n';
		}
	}
};

mat mul(mat &a,mat &b)
{
	mat tmp;

	for(int i = 0; i < x; i++)
	{
		for(int j = 0; j < x;j++)
		{
			tmp.a[i][j] = 0;

			for(int kk = 0; kk < x; kk++)
			{
				tmp.a[i][j] += a.a[i][kk] * b.a[kk][j];
				tmp.a[i][j] %= MOD;

			}
		}
	}
	return tmp;
}

mat expo(mat &mt , ll pow)
{
	mat tmp, ans;

	for(int i = 0; (1LL << i) <= pow;i++)
	{
		if(i == 0)
			tmp = mt;
		else 
			tmp = mul(tmp,tmp);
		if(pow &(1LL << i)){
			ans = mul(ans,tmp);
		}
	}
	return ans;
}

int main()
{
	cin >> n >> b >> k >> x;
	for(int i = 1; i <= n;i++)
	{
		int tmp;
		cin >> tmp,dig[tmp]++;
	}

	mat tmp;
	tmp.setter();
	tmp = expo(tmp,b);
	//tmp.print();
	ll ans = 0;

	ans = (tmp.a[k][0]) ;
	cout << ans << endl;

	return 0;
}