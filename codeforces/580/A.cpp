
#include <bits/stdc++.h>
#define PII pair < int , int >
#define PI 2.0*acos(0.0)
#define ll long long int
#define loop(i, a, n) for(int i = int (a); i < int (n); i++)
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
    //vector < int > adj[110];
    int n ;
    int a[up1];
    cin >> n;
    loop(i, 0, n){
    scanf("%d", &a[i]);
    }
    int rans = 1;
    int ans = 1;

    loop(i, 1, n){
     if(a[i] < a[i-1])
         rans = max(rans, ans), ans = 1;
     else
        ans++;
    }
    cout << max(rans, ans) << endl;

    return 0;
}
