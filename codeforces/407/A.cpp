#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,i;
    float f,fa,fb;
    cin>>a>>b;
    for(i=1;i<a;i++){
        f=sqrt(a*a-i*i);
        if(f-(int)f==0){
            fa=-1*(b*f)/a;
            fb=(b*i)/a;
            if(fa-(int)fa==0&&fb-(int)fb==0&&fb!=f){
                cout<<"YES\n0 0\n"<<i<<" "<<f<<"\n"<<fa<<" "<<fb;
                return 0;
            }
        }
    }
    cout<<"NO";
}