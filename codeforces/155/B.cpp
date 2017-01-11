#include <bits/stdc++.h>
 using namespace std;

bool cmp (pair <int, int > a, pair < int , int > b)
{
    if(a.first > b.first)
        return true;
    if(a.first < b.first)
        return false ;
    return (a.second > b.second);

}


int main()
{
    int n , t1, t2;
vector < pair < int, int > > v;
    cin >> n;
    for( int i = 1; i <= n ; i++)
    {
        scanf("%d %d", &t1, &t2);
        v.push_back(make_pair(t2, t1));
    }
    sort(v.begin(), v.end(), cmp);
    int cnt = 1;
    int ans  = 0;
    int len = v.size();
    for(int i = 0; i < len ; i++)
    {
        if(cnt == 0)
        break;
        cnt += (v[i].first -1);
        ans+= v[i].second;
    }
    cout << ans << endl;
    return 0;
}
