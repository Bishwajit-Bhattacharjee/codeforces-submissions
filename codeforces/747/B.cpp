#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i <= int (n); i++)
#define vi vector < int >
#define pb push_back
#define ceil(a, b) (a %b == 0)?(a/b):(a/b)+1
int const up =   1e6 + 10 ;
int  const up1 = 5 * 1e5 + 10  ;
int const eps = 1e-9;
int const mod = 10000007;
using namespace std;

//global variables



 // global variables  end here

 // functions begin here


 // functions end
 int main()
 {
    char s[1000], buf[10];
    map < char , int > e;
    e['A'] = 0; e['G'] = 0; e['C'] = 0; e['T'] = 0;
    //int a[26]={1000000};
    int len , n;
    scanf("%d", &len);
    gets(buf);
    gets(s);
   // puts(s);
    //len = strlen(s);

    for(int i = 0; i < len ; i++)
    {
        if(s[i] != '?')
           e[s[i]]++;
    }
    if( len % 4 != 0)
     { puts("===");  return 0;}
     int m = (len/4);
 /*   for(int i = 0; i < 26; i++)
    {
        if(a[i] > m && a[i] != 1000000)
        {
            puts("===");
            return 0;
        }
    } */
    if(e['A'] > m ||  e['G'] > m || e['C'] > m || e['T'] > m)
    {
        puts("===");
        return 0;

    }

    while(e['A'] < m)
    {
              //printf("ss\n");
              for(int j = 0 ; j < len; j++)
              {
                  if(s[j] == '?')
                  {
                    s[j] = 'A';
                    e['A']++;
                    break;
                  }
              }
          }

while(e['C'] < m)
          {
              //printf("ss\n");
              for(int j = 0 ; j < len; j++)
              {
                  if(s[j] == '?')
                  {
                    s[j] = 'C';
                    e['C']++;
                    break;
                  }
              }
          }

          while(e['G'] < m)
          {
              //printf("ss\n");
              for(int j = 0 ; j < len; j++)
              {
                  if(s[j] == '?')
                  {
                    s[j] = 'G';
                    e['G']++;
                    break;
                  }
              }
          }
          while(e['T'] < m)
          {
              //printf("ss\n");
              for(int j = 0 ; j < len; j++)
              {
                  if(s[j] == '?')
                  {
                    s[j] = 'T';
                    e['T']++;
                    break;
                  }
              }
          }
    puts(s);
    return 0;
}
