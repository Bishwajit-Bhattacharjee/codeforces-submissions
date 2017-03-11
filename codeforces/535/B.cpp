#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int len = 0;
	int ans = 0;
	while (n) {
		if (n % 10 == 7)
			ans += (1 << len);
		n /= 10;
		len++;
	}
	for (int i = 1; i < len; i++)
		ans += (1 << i);
	cout << ans + 1 << endl;
	return 0;
}