#include<bits/stdc++.h>
using namespace std;
int h[1005],hh[2],n;
string str;
void f(int i)
{
	int j;
	if(i==n)
	{
		cout<<"YES"<<endl;
		for(j=0;j<n;j++)cout<<h[j]<<' ';
		exit(0);
	}
	for(j=0;j<10;j++)
		if(str[j]=='1' and (!i or j+1!=h[i-1]) and hh[i%2]+j>=hh[(i+1)%2])
		{
			hh[i%2]+=h[i]=j+1;
			f(i+1);
			hh[i%2]-=j+1;
		}
}
int main()
{
	cin>>str>>n;
	f(0);
	cout<<"NO"<<endl;
}