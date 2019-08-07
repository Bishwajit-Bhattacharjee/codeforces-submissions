#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef pair<int,int> PII;
typedef long long int ll;
typedef pair< ll,ll> PLL;
typedef unsigned long long int ULL;
typedef pair<ULL,int> PUI;
#define S second
#define F first
typedef tree<
PLL,
null_type,
less<PLL>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;


PLL operator+(PLL a,PLL b){ return {a.first + b.first, a.second + b.second}; }
PLL operator-(PLL a,PLL b){ return {a.first - b.first, a.second - b.second}; }
PLL operator*(PLL a,PLL b){ return {a.first * b.first, a.second * b.second}; }
PLL operator/(PLL a,PLL b){ return {a.first / b.first, a.second / b.second}; }
PLL operator%(PLL a,PLL b){ return {( b.first + a.first) % b.first, (b.second + a.second) % b.second}; }
PLL operator%(PLL a,ll b){ return {a.first % b, a.second % b} ;}
PLL operator+(PLL a,ll b){ return {a.first + b, a.second + b} ;}
PLL operator-(PLL a,ll b){ return {a.first - b, a.second - b} ;}
PLL operator*(PLL a,ll b){ return {a.first * b, a.second * b} ;}

ostream& operator<<(ostream &out,PLL a)
{
    out << "( " << a.first << ", " << a.second << " )" ;
    return out;
}

ostream& operator<<(ostream &out,PUI a)
{
    out << "( " << a.first << ", " << a.second << " )" ;
    return out;
}
/*
	Order Statistics Tree ( OST )

	find_by_order()
		takes an integer k and returns an iterator to the k'th largest element counting from zero
	order_of_key()
		takes an element, here an integer and returns the number of elements strictly smaller than input
*/


int const MOD = 1e9 + 7;

int const N = 1e5 + 10;
bool mark[N] ;

void sieve()
{
    for(int i = 2; i < N; i++){
        if(!mark[i]){
            for(int j = 2 * i ; j < N; j += i) 
                mark[j] = 1;
        }
    }
}
int a[20][20][20][20];
int dist[20];
int vis[20];

void bfs(int fr,int x,int y)
{
    queue < int > q;
    q.push(fr);
    memset(vis,0,sizeof vis);

//    dist[]
    //vis[fr] = 0;

    int a = fr + x;
    int b =  fr + y;

    a %= 10, b %= 10;
    if(!vis[a]){
        dist[a] =  1;
        q.push(a);
        vis[a] = 1;
    }
    if(!vis[b]){
        dist[b] =  1;
        q.push(b);
        vis[b] = 1;
    }

    while(!q.empty()){
        int n = q.front();
        q.pop();
        int a = n + x;
        int b =  n + y;
        a %= 10, b %= 10;
        if(!vis[a]){
            dist[a] = dist[n] + 1;
            q.push(a);
            vis[a] = 1;
        }
        if(!vis[b]){
            dist[b] = dist[n] + 1;
            q.push(b);
            vis[b] = 1;
        }
    }
}
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    memset(a,0x7F,sizeof a);
    
    for(int x = 0; x <= 9; x++){
        for(int y = 0; y <= 9; y++){
            for(int fr = 0; fr <= 9; fr++){
                memset(dist,0x7F,sizeof dist);
                //dist[fr] = 0;
                bfs(fr,x,y);
                for(int to = 0; to <= 9; to++){
                    a[fr][to][x][y] = dist[to];
                }
            }
        }
    }
    //cout << a[0][0][0][0] << endl;
    //for(int i = 0; )    
    
    string s;
    cin >> s;

    for(int x = 0; x <= 9; x++){
        for(int y = 0; y <= 9; y++){
            ll cnt = 0;
            for(int i = 1; i < s.size(); i++){
                ll tmp = a[s[i-1]-'0'][s[i]-'0'][x][y];
                if(tmp > 1e7){
                    cnt = 1e15;
                    break;
                }
                else 
                    cnt += max(0LL,(tmp - 1));
            }
            if(cnt > 1e14){
                cout << "-1 ";
            }
            else 
                cout << cnt << " ";
        }
        cout << '\n';
    }
    return 0;

}