#include <bits/stdc++.h>

using namespace std;

const int mx = 1e5;
    bool f[mx];

int main() {
	// your code goes here
    string s;
    cin >> s;
    bool done = 0;
  //  reverse(s.begin(),s.end());
    for(int i = 0 ;i < s.size(); i++)
    {
        if(s[i] - '0' == 0)
        {
            f[i] = 1;
            done = 1;
            break;
        }
    }
    if(done)
    {
       for(int i = 0; i < s.size(); i++){
           if(!f[i])
               cout << s[i];
       }
    }
    else 
        for(int i = 1; i < s.size(); i++)
            cout << s[i];
    
  
	return 0;
}