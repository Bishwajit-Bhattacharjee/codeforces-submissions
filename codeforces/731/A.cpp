#include <bits/stdc++.h>
#define PII pair < int , int >
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
int const up1 = 1e3 + 10;
int const up =  (int) sqrt(1000000000*2 + 1);
using namespace std;

int main()
{
    string s;
    int n;
    int ans = 0;
    cin >> s;
    char t = 'a';
    for(int i = 0; i < s.size(); i++)
    {
        ans += min(abs(s[i]-t), (26-abs(s[i]-t)));
        //cout << ans << endl;
        t = s[i];
    }
    cout << ans << endl;




    return 0;
}
