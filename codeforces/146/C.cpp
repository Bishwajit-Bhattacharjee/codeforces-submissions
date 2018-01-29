#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b;
    cin >> a >>  b;
    int t1 , t2 ;
    t1 = t2 = 0;
    for(int i = 0; i < a.size(); i++) {
        if(a[i] =='7'&& b[i] == '4')t1++;
        else if(a[i] =='4' && b[i] =='7')t2++;
    }
    cout << max(t1 ,t2) << endl;
    return 0;
}
