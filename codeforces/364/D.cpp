#include <bits/stdc++.h>

using namespace std;

#define si(a) scanf("%d",&a)
#define f first
#define s second
#define mp(a,b) make_pair(a,b)
#define ITR 10
#define MAX 1000005

long long ans=1;
long long ara[MAX];
int n;
vector<long long> divisor;
int cnt[100005];
map<long long,int> vis;

bool do_it(void)
{
    long long now=ara[((long long)rand()*1005ll)%n];
    if(vis[now])return false;
    vis[now]=1;
    divisor.clear();
    for(long long i=1;i*i<=now;i++){
        if(now%i==0){
            divisor.push_back(i);
            if(now!=i*i)divisor.push_back(now/i);
        }
    }
    sort(divisor.begin(),divisor.end());
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<n;i++)cnt[lower_bound(divisor.begin(),divisor.end(),__gcd(now,ara[i]))-divisor.begin()]++;
    for(int i=1;i<divisor.size();i++){
        for(int j=0;j<i;j++){
            if(divisor[i]%divisor[j]==0)
                cnt[j]+=cnt[i];
        }
    }
    for(int i=0;i<divisor.size();i++)if(2*cnt[i]>=n)ans=max(ans,divisor[i]);
    return true;
}

int main()
{
    //freopen("input.txt","r",stdin);
    si(n);
    for(int i=0;i<n;i++)scanf("%I64d",&ara[i]);
    srand(clock());
    int arek=1005;
    for(int i=0;i<ITR && arek;i++){
        if(!do_it()){
            i--;
            arek--;
        }
    }
    cout<<ans<<endl;
    return 0;
}