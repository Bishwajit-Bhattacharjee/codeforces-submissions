#include <bits/stdc++.h>
using namespace std;

int main()
{
        string s1, s2;
        cin >> s1 >> s2;

        int sz = __gcd(s1.size(), s2.size());
        vector < int > divisors;

        for(int i = 1; i <= sz; i++)
        {
                if(sz % i == 0)
                        divisors.push_back(i);

        }
        int ans = 0;
        for(int i = 0;i < divisors.size(); i++)
        {
                bool f1 =0 ,  f2 = 0;

                string tmp = "" , loop = "";

                int curSize = divisors[i] ;
                tmp = s1.substr(0, curSize) ;

                while(loop.size() < s1.size() or loop.size() < s2.size())
                {
                        loop += tmp;
                        if(loop.size() == s1.size() )
                                f1 = (loop == s1 );
                        if(loop.size() == s2.size() )
                                f2 = (loop == s2) ;
                }
                if(f1 && f2) ans++;

        }
        cout << ans << endl;
        return 0;
}
