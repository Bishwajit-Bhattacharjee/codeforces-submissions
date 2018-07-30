#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	while(cin >> n) 
	{
		if(n & 1 or n == 2) 
			cout << "NO" << endl;
		else
			cout << "YES" << endl;
	}
	return 0;
}