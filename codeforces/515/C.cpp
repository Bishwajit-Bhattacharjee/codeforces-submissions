
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


 // functions end


int main()
{
    int a[11] = {0};
    char s[20], buf[10];
    int n;
   // cin >> n;
   // string s;
   // cin >> s;
    scanf("%d", &n);
    gets(buf);
    gets(s);
   // puts(s);
    for(int i = 0; i < n; i++){
        if(s[i] == '0' || s[i] == '1')
            continue;
        else if(s[i] == '2' || s[i] == '3' || s[i] == '5' || s[i] == '7')
            a[s[i] - '0']++;
        else if(s[i] == '4')
            a[3]++, a[2] += 2;
        else if(s[i] == '6')
            a[3]++, a[5]++;
        else if(s[i] == '8')
            a[2] += 3, a[7]++;
        else if(s[i] == '9')
            a[2]++, a[3]+= 2, a[7]++;
    }
    string ans;
    for(int i = 9; i > 1; i--)
    {
        while(a[i])
        {
            printf("%c",(char)('0' + i));
         //   ans += char('0'+ i);
            a[i]--;
        }

    }
   // cout << ans << endl;
    return 0;
}
