#include <bits/stdc++.h>
using namespace std;

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);

        vector<long long> cnt(5,0);
        vector<int>price(5,0);

        int n;
        cin >> n;
        vector<int>bar(n,0) ;
        long long left =0;

        for(int i =0 ; i < n;i++)
                cin >> bar[i] ;

        for(int i = 0; i < 5;i++)
                cin >> price[i] ;

        for(int i = 0; i < n;i++)
        {

                left += bar[i];

                for(int i = 4; i >= 0; i--)
                {
                        long long tkn = left/price[i] ;
                        cnt[i] += tkn;
                        left %=  price[i];

                }
        }

        for(int i =0 ; i < 5; i++)
                cout << cnt[i] << ' ' ;

        cout << endl;
        cout << left << endl;


        return 0;
}
