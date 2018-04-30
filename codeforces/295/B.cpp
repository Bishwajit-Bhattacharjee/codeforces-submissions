#include <bits/stdc++.h>
using namespace std;

int const MX = 550 ;

long long ara[MX][MX] ;


int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0) ; cout.tie(0);

        int n;
        cin >> n;


        for(int i = 1; i <= n ;i++)
        {
                for(int j = 1; j <= n;j++)

                        cin >> ara[i][j] ;
        }

        vector < int > seq(n) ;

        for(int i = 0 ;i < n; i++)
                cin >> seq[i];

        vector < int > now;
        vector< long long > ans(n,0);

        vector< int > tmp(n);
        for(int i = 0; i < n;i++)
                tmp[i] = i+1;

        for(int k = n - 1; k >= 0; k--)
        {
                int sum = 0;
                now.push_back(seq[k]);
                int lat = seq[k] ;

                for(auto i : tmp)
                {
                        for(auto j : tmp)
                        {
                                ara[i][j] = min(ara[i][j],
                                                ara[i][seq[k]] + ara[seq[k]][j]);
                        }
                }
                ans[k] = 0;

                for(auto i : now)
                {
                        for(auto j: now)
                                ans[k] += ara[i][j];

                }

        }

        for(auto a : ans)
                cout << a << ' ' ;


        return 0;
}
