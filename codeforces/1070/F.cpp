#include <bits/stdc++.h>
#define ll      	long long int
#define PI      	acos(-1)
#define read    	freopen("in.txt","r",stdin)
#define uu      	first
#define vv      	second
#define write   	freopen("out.txt","w",stdout)
#define pii     	pair<int,int>
#define INF     	1e9
#define EPS     	1e-8
#define MAX     	1000006
#define MOD     	1000000007
#define fastRead 	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll n ;
vector<ll>v1 , v2 , v3;
string str;
ll sum  , taken , a , b , tmp;
int main()
{
    fastRead;
    cin>>n;
    for(int i =0 ; i < n ; i++ ) {
        cin>>str>>tmp;
        if( str== "11") {
            sum += tmp;
            a++;
            b++;
            taken++;
        }
        else if( str == "00") {
            v1.push_back(tmp);
        }
        else if(str == "01") {
            v2.push_back(tmp);
        }
        else if( str=="10") {
            v3.push_back(tmp);
        }
    }
    if( v2.size() > v3.size()) {
        swap(v2,v3);
    }
    sort(v2.rbegin() , v2.rend());
    sort(v3.rbegin() , v3.rend()); // v2 choto

    for(int i =0 ; i < v2.size() ; i++ ) {
        sum += v2[i];
        sum += v3[i];
        a++;
        b++;
        taken +=2;
    }

    for(int i =  v2.size() ; i< v3.size() ; i++)  {
        v1.push_back(v3[i]);
    }

    sort(v1.rbegin() , v1.rend());


    for(int i =0 ; i < v1.size() ; i++ ) {
        if( 2* a >= (taken + 1) ) {
            sum += v1[i];
            taken++;
        }
        else break;
    }
    cout<<sum<<endl;
    return 0;

}
