#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e4 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    int n;
    bool flag = false;
    char str[1000] , buf[10];
    scanf("%d", &n);
    gets(buf);
    gets(str);
    int len = strlen(str);
    int inlen = 0, outlen = 0;
    int inc  = 0, m_out = 0;
    for(int i = 0; i < len; i++)
    {
        if(str[i] == '(')
        {
            m_out = max(m_out, outlen);
            outlen  = 0;
             inlen = 0;i++;
            while(str[i] != ')')
            {

               if(str[i] == '_')
                {

                 if(inlen > 0)inc++;
                    inlen = 0;
                }
                else
                    inlen++;
                i++;
               //printf("\n%d ", inc);
            }
           // m_in = max(m_in, inlen);
           if(inlen > 0)
            inc++;
            //printf("\n%d", inc);
        }

        else if(str[i] == '_')
        {
         m_out = max(m_out, outlen);
            outlen = 0;
            //flag = true;
        }
        else
            outlen++;

    }
     m_out = max(m_out, outlen);

    cout << m_out << ' ' << inc;
    return 0;
}
