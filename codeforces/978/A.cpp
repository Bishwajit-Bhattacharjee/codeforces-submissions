#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector < int > v(n) ;

    for(int i = 0; i < n; i++)
        cin >> v[i] ;

    for(int i = v.size() - 1; i >=0 ; i--)
    {
        for(int j = i - 1; j >= 0 ; j--)
        {
            if(v[i] == v[j] )
                v[j] = -1;


        }
    }
    int cnt =0 ;
    for(int i =0 ; i < n; i++)
        cnt += (v[i] != -1) ;
    cout << cnt << endl;
    for(int i = 0 ; i < n ; i++)
        if(v[i] != -1)
            cout << v[i] << ' ' ;

    return 0;
}
