#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
typedef long long ll;
typedef pair<int,int> PII;
const int up = 1e5 +5;
#define loop(i , a , b) for(int i = int(a);  i <= int(b); i++)
#define vi(x) vector<int> x;

int main()
{
   char str1[100], str2[100];
   int id  = 0;
   gets(str1);
   gets(str2);
   for(int i =0 ; i < strlen(str2); i++){
    if(str2[i] == str1[id]){
        id++;
    }
   }
   cout << ++id << endl;
  // printf()



   return 0;
}
