#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    int mm = m;
    if(m < n - 1)
        return cout << "Impossible",0;
    vector < pair < int ,int > > v;

    for(int i = 1; m && i <= n; i++)
    {
        for(int j = i + 1; j <= n && m ; j++)
        {
            if(__gcd(i,j) == 1)
            {
                //printf("%d %d\n",i,j) ;
                v.push_back({i,j}) ;
                m--;
            }
        }
    }
    if(v.size() != mm)
        cout << "Impossible"<< endl;
    else {
        cout << "Possible" << endl ;
        for(int i = 0; i < v.size(); i++)
        {
            printf("%d %d\n",v[i].first, v[i].second) ;
        }
    }
    return 0;
}
