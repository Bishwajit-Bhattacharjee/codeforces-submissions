#include<bits/stdc++.h>
using namespace std;
const int M=1e5+1;
vector<int>v[M],r[M],comp;
vector<vector<int> >temp;
long long ways=1;
vector<pair<int,int> >u;
int ct,n,e;
long long cost[M],mn=999999999999;
bool vis[M];
void dfs(int x)
{
	ct++;
	vis[x]=1;
	for(int i=0;i<v[x].size();i++)
		if(!vis[v[x][i]])
			dfs(v[x][i]);
	u.push_back(make_pair(ct,x));
	ct++;
}
void DFS(int x)
{
	vis[x]=1;
	mn=min(mn,cost[x]);
	for(int i=0;i<r[x].size();i++)
		if(!vis[r[x][i]])
			DFS(r[x][i]);
	comp.push_back(x);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		scanf("%d",&cost[i]);
	cin>>e;	
	for(int i=0;i<e;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		r[y].push_back(x);
	}
	for(int i=1;i<=n;i++)
		if(!vis[i])
			dfs(i);
	sort(u.begin(),u.end());
	reverse(u.begin(),u.end());
	memset(vis,0,sizeof(vis));
	long long ans=0;
	for(int i=0;i<u.size();i++)
	{
		int lel=0;
		if(!vis[u[i].second])
		{
			DFS(u[i].second);
			ans+=mn;
			for(int j=0;j<comp.size();j++)
				if(cost[comp[j]]==mn)
					lel++;
			comp.clear();
			mn=999999999999;
			ways*=lel;
			ways%=1000000007;
		}
	}
	cout<<ans<<" "<<ways;
}