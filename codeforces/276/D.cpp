#include <bits/stdc++.h>
using namespace std;

int main()
{
        long long a, b, ans = 0;

        cin >> a >> b;

        bool done = false;

        for(int i = 63; i >=0 ; i--)
        {
                if((a & (1LL << i)) != (b & ( 1LL << i )) )
                        done = true;

                if(done)
                        ans |= (1LL << i ) ;
        }
        cout << ans << endl;
        return 0;
}
