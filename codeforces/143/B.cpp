#include<iostream>
using namespace std;
int n,k,p,i,j,c,t;
main(){
	string s;
	cin>>s;
	if(s[0]=='-'){cout<<"(";j=1;t=1;}
	p=s.find(".");
	cout<<"$";
	if(p==-1){k=s.size();}
	else {k=p;} 
	for(i=j;i<k;i++){c++;
	cout<<s[i];
	if((k-i-1)%3==0&&i<k-1){cout<<",";}} 
	if(p==-1){cout<<"."<<"00";}
	else
	if(p==s.size()-2&&p>1){cout<<s[k]<<s[k+1]<<"0";}
	else
	if(p==s.size()-3&&p>1||(s.size()-p>2)){cout<<s[k]<<s[k+1]<<s[k+2];}
	if(t){cout<<")";}}