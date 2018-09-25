#include<bits/stdc++.h>
//using namespaces 

using namespace std;


int main(){
  long long k,b,n,t,a=1;        
  cin>>k>>b>>n>>t;
  while(a<=t){
    a = a*k+b;
    n--;
  }
  n++;
  cout<<(n>=0?n:0)<<endl;
  return 0;

}