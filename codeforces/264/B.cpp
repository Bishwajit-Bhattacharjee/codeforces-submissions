#include<bits/stdc++.h>
using namespace std;

int const MX = 1e5 + 10;
vector<int>divi[MX];

int dp[MX];
int has[MX] ;
int d[MX] ;


int main()
{
        for(int i = 2; i < MX; i++)
                for(int j = i*2 ; j < MX; j+= i)
                        divi[j].push_back(i);


        ios_base::sync_with_stdio(false) ;
        cin.tie(0);

        int n;
        cin >> n;

        while(n--){
                int tmp;
                cin >> tmp;
                has[tmp] = 1;

        }
//        for(int i = 1; i < MX; i++)
//                dp[i] = 1;

//        for(int i = 1; i< 10; i++){
//                for(auto div : divi[i] )
//                        cout << div << ' ' ;
//                cout << endl;
//        }

        fill(d + 1, d + MX ,0);
        fill(dp + 1, dp + MX, 0 );

        for(int i = 1;i < MX; i++)
        {
                if(has[i] == 0 ) continue;

                int mx = 0;

                for(auto div : divi[i])
                        mx = max(mx, d[div]);
                dp[i] = mx + 1;

                for(auto div : divi[i])
                        d[div] = max(d[div] , dp[i] );
                d[i] = dp[i] ;

        }
//        for(int i= 1; i <= 10 ;i++)
//                cout << dp[i] << endl;

        cout << *max_element(dp + 1, dp + MX) << endl;


        return 0;
}
