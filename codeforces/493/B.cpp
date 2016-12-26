#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef  long long ll;
typedef pair<int,int> PII;
const int up = 1e3;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;
//#define end return 0
int main()
{
     ll n,tmp ;
    cin >> n;
    //string s1, s2;
   // vector < char > s1, s2;
    //(s1); vi(s2);
    vector < ll > s1;
    vector < ll > s2;
    ll l1, l2, sum1 =  0, sum2 = 0;
    char ch ;
    bool g= false;
    loop(i, 0 , n-1)
    {
        //scanf("%d", &tmp);
        cin >> tmp;
        if(i == n-1)
        {
            (tmp > 0)?g = true: g = false;
        }
        if(tmp > 0)
        {
            l1 = tmp;
            sum1+= tmp;
            //s1.pb(tmp + '0');
            s1.pb(tmp);

        }
        else
        {
            tmp *= -1;
            l2 = tmp;
            sum2+= tmp;
            //s2.pb(tmp + '0');
            s2.pb(tmp);
        }
    }
    if(sum1 > sum2)
        {puts("first") ; return 0;}

    else if(sum1 < sum2)
     {
         puts("second");
         return 0;
     }
    else
    {
        int len = min(s1.size(), s2.size());
        for(int i = 0; i < len; i++)
        {
            if(s1[i] > s2[i])
           {
               puts("first") ; return 0;}

            else if(s1[i] < s2[i])
            {
              puts("second");
               return 0;
            }
        }

       g?puts("first"):puts("second");

    }


    return 0;
}

