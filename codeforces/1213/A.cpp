#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    vector <int> v(n);
    int a[2] = {0,0};

    for(int i = 0; i < n; i++){
        cin >> v[i];
        a[v[i]&1]++;
    }
    sort(a,a+2);
    cout << a[0] << endl;
    return 0;
}