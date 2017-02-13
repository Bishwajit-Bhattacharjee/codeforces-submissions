
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const array_size = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here

 bool can (int m, int s)
 {
    return (s >= 0  && s <= 9 * m);
 }

 // functions end


int main()
{
    string minn, maxx;
    int m, s;
     cin >> m >> s;
    int sum = s;
    if((s == 0 && m != 1) || (m * 9 < s))
    {
        printf("-1 -1");
        return 0;

    }
    for(int i = 0; i < m; i++)
    {
        for(int d = 0;d < 10 ; d++)
        {
            if((i >0 || d > 0 || (m == 1 && d == 0)) && can(m - i - 1, sum - d))
                {  minn += char('0' + d), sum -= d; break;}

        }
    }
    sum = s;
    for(int i = 0 ; i < m;i++)
    {
        for(int d = 9 ; d >= 0; d--)
        {
            if(can(m - i - 1, sum - d))
            {
                maxx += char('0'+d);
                sum -= d;
                break;
            }
        }
    }
    cout << minn << ' ' << maxx << endl;
    return 0;
}
