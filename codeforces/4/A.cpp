#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main(){
    int n;
    cin >> n;
    string ans ;
    if(n == 2 or n % 2 == 1)
        ans = "NO";
    else
        ans = "YES";
    cout << ans << endl;

    return 0;
}