#include <iostream>
using namespace std;

int main()
{
    int t_x,t_y,x=0,y=0,turn=1;
    cin>>t_x>>t_y;
    int ans=0;
    while(true){
        int next_x=x,next_y=y;
        if(turn==1)
            next_x=-x+1;
        else if(turn==2)
            next_y=-y+1;
        else if(turn==3)
            next_x=-x;
        else
            next_y=-y;
        if((t_x>=min(next_x,x) && t_x<=max(next_x,x)) && (t_y>=min(next_y,y) && t_y<=max(next_y,y)))
            break;
        ans++;
        turn++;
        if(turn==5)
            turn=1;
        x=next_x;
        y=next_y;
    }
    cout<<ans<<endl;
    return 0;
}