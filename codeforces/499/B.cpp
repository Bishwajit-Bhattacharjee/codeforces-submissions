
#include <bits/stdc++.h>

using namespace std;
map <string, string> a;

int main()
{
    int n ,m ;
    cin >> n >> m;
    string s, t;

    while(m--)
    {
        cin>>s>>t;

        a[s] = ((t.size() < s.size())?t:s);

    }
    while(n--)
    {
        string x;
        cin>>x;
       // printf("%s ", a[x]);
       cout<<  a[x]  <<' ';
    }


	return 0;
}



