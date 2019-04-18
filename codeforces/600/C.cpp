#include <bits/stdc++.h>

using namespace std;
typedef pair < int,int >  PII;
int const N = 50;

int cnt[30] ;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string s;
    cin >> s;
    
    for(auto x : s)
        cnt[x-'a']++;
    
    int op = 0;
    for(int i = 26; i >= 0; i--)
    {
        if(cnt[i] & 1)
        {
            bool f = 0;
            for(int j = 0; j <= i - 1 ; j++)
            {
                if(cnt[j] & 1){
                    cnt[j]++; op++; cnt[i]--; break;
                }
            }
        }
    }
    
    deque < char > dq;
    
    for(int i =0 ;i < 26; i++)
    {
        if(cnt[i] & 1)
        {
            while(cnt[i] & 1)
                dq.push_back((char)(i+ 'a')), cnt[i]--;
        }
    }
    for(int i = 26; i >= 0; i--)
    {
        if(cnt[i] % 2 == 0)
        {
            int half = cnt[i] / 2;
            int half2 = half;
            while(half)
                dq.push_back((char)(i+'a')), dq.push_front((char)(i+'a')),half--;
            //while()
            
        }
    }
    
    for(auto x : dq)
        cout << x ;
    cout << endl;
    return 0;
}