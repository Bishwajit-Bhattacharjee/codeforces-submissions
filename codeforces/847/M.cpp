#include <bits/stdc++.h>
using namespace std;

typedef long long int ll ;
typedef pair < int , int > PII ;
#define pb push_back
//#define mp make_pair
#define F first
#define S second

int const MX = 2 * 1e5 + 10 ;

int a[110] ;
int main()
{
    int n ;
    cin >> n ;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]) ;

    }
    set < int > s ;
    for(int i = 2 ; i <= n; i++)
        s.insert(a[i] - a[i-1]) ;
    if(s.size() == 1) {

        cout << a[n] + *s.begin() << endl;
    }
    else {
        cout << a[n] << endl ;
    }
    return 0;
}
