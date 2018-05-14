#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    string s;
    cin >> s ;
    s += '0';
    int cnt = 0;
    int ans =0 ;
    for(int i = 0 ; i < s.size(); i++)
    {
        if(s[i] == 'x')cnt++;
        else
            ans += max(0, cnt - 2) , cnt = 0;
    }
    cout << ans << endl;
    return 0;
}
