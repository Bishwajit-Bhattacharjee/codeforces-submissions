#include<iostream>
#define M 1003
#define f(i,a,b) for(int i=a;i<b;i++)
using namespace std;
int main(){
	int a[M][M],b[M][M],m,n,p;
	cin>>n>>m;
	f(i,0,n)f(j,0,m){cin>>b[i][j];a[i][j]=1;}
	f(i,0,n)f(j,0,m)if(b[i][j]==0){
		f(k,0,n)a[k][j]=0;
		f(k,0,m)a[i][k]=0;
	}
	f(i,0,n)f(j,0,m){
		p=0;
		f(k,0,n)p|=a[k][j];
		f(k,0,m)p|=a[i][k];
		if(p!=b[i][j]){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	f(i,0,n){f(j,0,m)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}