#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e7 + 1;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)

#define vi(x) vector<int> x;

int main()
{
    string s1, s2, s;
    int n;
    cin >> n;
    while(n--)
    {
        cin >> s;
        s1+= s;
    }
    s2 = s1;
    reverse(s1.begin(), s1.end());
    if(s2 == s1)
        printf("YES\n");
    else
        printf("NO\n");


    return 0;

}
