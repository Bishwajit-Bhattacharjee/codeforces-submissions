#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,x,y;
	vector<int>v,s;
	v.push_back(0);
	s.push_back(0);
	double avg=0;
	cin>>n;
	for(int t,i=0; i<n; ++i){
		scanf("%d",&t);
		if(t==1){
			scanf("%d%d",&x,&y);
			avg+=x*y;
			s[x-1]+=y;
		}else if(t==2){
			scanf("%d",&x);
			avg+=x;
			s.push_back(0);
			v.push_back(x);
		}else{
			avg-=(v[v.size()-1]+s[s.size()-1]);
			s[s.size()-2]+=s[s.size()-1];
			s.pop_back();
			v.pop_back();
		}
		printf("%.6lf\n",avg/s.size());
	}
}