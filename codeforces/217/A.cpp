#include <bits/stdc++.h>
using namespace std;
bool f[1001][1001];bool f_p[1001][1001];
typedef struct {
    int x;
    int y;
}point ;
point a[110];

void dfs(point p)
{
    f[p.x][p.y] = 1;
    for(int x = 1; x <= 1000 ; x++){
        if(f_p[x][p.y] && !f[x][p.y]) dfs(point{x, p.y});
    }
    for(int y = 1; y <= 1000 ; y++){
        if(f_p[p.x][y] && !f[p.x][y]) dfs(point {p.x, y});
    }
}
int main()
{
    int n ;cin >> n;for(int i = 0; i < n; i++)cin >> a[i].x >> a[i].y, f_p[a[i].x][a[i].y] = 1;
    int ans = 0;
    for(int i = 0 ; i < n ;i++){
        if(!f[a[i].x][a[i].y]){
            ans++; 
            dfs(a[i]);
        }
    }
    cout <<( (ans == 0)? ans : ans - 1 )<< endl;
}