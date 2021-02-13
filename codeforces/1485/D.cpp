#include <bits/stdc++.h>
using namespace std;
using ll = long long int;

int b[510][510];

int main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) cin >> b[i][j];

    ll g = 720720;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            if ((i+j)&1) cout << g;
            else cout << g + b[i][j]*b[i][j]*b[i][j]*b[i][j]; 
            cout << " ";
        }
        cout << "\n";
    }
}