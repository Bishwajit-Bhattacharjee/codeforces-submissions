#include <iostream>
#include <cstdio>
using namespace std;

char a[55][55],b[55][55];
int na,ma,nb,mb;

int func(int x,int y)
{
    int ans=0;
    int i,j;
    for(i=0;i<na;i++){
        if(i+x>=nb || i+x<0)
            continue;
        for(j=0;j<ma;j++){
            if(j+y>=mb || j+y<0)
                continue;
            ans+=((a[i][j]-'0')*(b[i+x][j+y]-'0'));
        }
    }
    return ans;
}

int main()
{
    int i,j;
    cin>>na>>ma;
    for(i=0;i<na;i++)
        cin>>a[i];
    cin>>nb>>mb;
    for(i=0;i<nb;i++)
        cin>>b[i];
    int ans_x,ans_y,maximum=-1;
    for(i=-100;i<=100;i++){
        for(j=-100;j<=100;j++){
            int maxi=func(i,j);
            if(maxi>=maximum){
                maximum=maxi;
                ans_x=i;
                ans_y=j;
            }
        }
    }
    cout<<ans_x<<" "<<ans_y<<endl;
    return 0;
}