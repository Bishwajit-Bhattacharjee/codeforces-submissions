#include <bits/stdc++.h>
using namespace std;
int const MX = 550;
vector < int >  dp[MX][5] ;
//vector < int > par[MX][5] ;
bool isPrime[MX] ;
vector < int > prime;
void sieve()
{
    fill(isPrime,isPrime + MX,1);
    isPrime[1] = isPrime[0] = 0;
    for(int i = 2; i * i < MX ; i++)
    {
        if(isPrime[i]){
            //prime.push_back(i);
            for(int j = i*2; j < MX; j += i )
                isPrime[j] = 0;
        }
    }
    for(int i = 1; i < MX; i++)
        if(isPrime[i])
            prime.push_back(i);
}

bool again(int num)
{
    for(long long i = 2; i * i <= num; i++){
        if(num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{

    sieve();
    for(auto x : prime){
        for(auto y : prime){
            for(auto z : prime) {
                if(x + y + z >= MX )
                    continue;
                if(!dp[x+y+z][3].size()){
                    dp[x+y+z][3].push_back(x);
                    dp[x+y+z][3].push_back(y);
                    dp[x+y+z][3].push_back(z);
                }
            }
        }
    }
    for(auto x : prime)
    {
        for(auto y : prime){
            if(x + y >= MX ) continue;

            if(!dp[x+y][2].size()){
                    dp[x+y][2].push_back(x);
                    dp[x+y][2].push_back(y);
                    //dp[x+y+z][3].push_back(z);
                }
        }
    }
    for(auto x : prime)
        dp[x][1].push_back(x);
    int n;
    cin >> n;

    if(n < MX){
        if(dp[n][3].size()){
            cout << " 3\n";
            for(auto x : dp[n][3])
                    cout << x << " " ;
            return 0;
        }
        if(dp[n][2].size()){
            cout << "2" << endl;
            for(auto x : dp[n][2])
                cout << x << " " ;
            return 0;
        }
        cout << "1" << endl;
        cout << n << endl;
        return 0;

    }
    if(again(n)){
        cout << "1" << endl;
        cout << n << endl;
        return 0;
    }
    for(int i = n - 1; ; i--){
        if(again(i)){
            if(dp[n-i][2].size()){
                cout << " 3\n";
                cout << i << " " ;
                for(auto x : dp[n-i][2])
                    cout << x << " " ;
                return 0;
            }
            if(dp[n-i][1].size()){
                cout << " 2\n";
                cout << i << " " ;
                for(auto x : dp[n-i][1])
                    cout << x << " " ;
                return 0;
            }
        }
    }
    return 0;
}
