#include<bits/stdc++.h>
#define lli long long int
using namespace std;

struct  point{
    int x;
    int y;
    int hx,hy;
};

int n;
point ara[4][4];


point rot( point p) {
    p.x-=p.hx;
    p.y-=p.hy;

    int xnew= -p.y;
    int ynew=  p.x;

    p.x= xnew + p.hx;
    p.y = ynew + p.hy;

    return p;
}

lli dst( point p1, point p2) {
    lli ans = (lli)(p1.x- p2.x)*(p1.x -p2.x) + (lli)(p1.y- p2.y)*(p1.y -p2.y);
    return ans;
}


bool isSquare (point p1, point p2, point p3, point p4) {

    lli bahu=1e16;
    lli korno=0;

    lli  d1= dst ( p1,p2);
    bahu=min ( bahu,d1);
    korno = max( korno , d1);

    lli  d2= dst ( p1,p3);
    bahu=min ( bahu,d2);
    korno = max( korno , d2);

    lli  d3= dst ( p1,p4);
    bahu=min ( bahu,d3);
    korno = max( korno , d3);

    lli  d4= dst ( p2,p3);
    bahu=min ( bahu,d4);
    korno = max( korno , d4);

    lli  d5= dst ( p2,p4);
    bahu=min ( bahu,d5);
    korno = max( korno , d5);

    lli  d6= dst ( p3,p4);
    bahu=min ( bahu,d6);
    korno = max( korno , d6);

    //cout<<bahu<<" "<<korno<< " "<<endl;
    if( bahu<=0 || korno<=0) return false;

    //cout<<1<<endl;
    int cntbahu=0;
    int cntkorno=0;
    //cout<<d1<< " "<<d2<<" "<<d3<<" "<<d4<<" "<<d5<< " "<<d6<<endl;
    if( d1==bahu ) cntbahu++;
    if( d2==bahu ) cntbahu++;
    if( d3==bahu ) cntbahu++;
    if( d4==bahu ) cntbahu++;
    if( d5==bahu ) cntbahu++;
    if( d6==bahu ) cntbahu++;

    if( d1==korno ) cntkorno++;
    if( d2==korno ) cntkorno++;
    if( d3==korno ) cntkorno++;
    if( d4==korno ) cntkorno++;
    if( d5==korno ) cntkorno++;
    if( d6==korno ) cntkorno++;
    //cout<<cntkorno<<" "<<cntbahu<<endl;

    if( cntkorno!=2 || cntbahu != 4) return false;
    return true;
}

int main()
{
    scanf("%d",&n);
    for(int i=0 ;i <n ;i++) {

        memset(ara,0,sizeof(ara) );

        for(int j=0 ; j<4;j++) {

            point tmp;
            scanf("%d %d %d %d",&tmp.x,&tmp.y,&tmp.hx,&tmp.hy);
            ara[j][0]=tmp;

            for(int k=1 ;k<4;k++ ) {

                point t;
                t=rot(ara[j][k-1] );
                ara[j][k] = t;
                //cout<< ara[j][k].x <<" "<<ara[j][k].y<<endl;;

            }
            //cout<<endl;
        }
        int ans=1000000;
        for(int j = 0 ;j< 4;j ++) {

            for(int k= 0; k<4 ;k++) {

                for (int l =0; l<4; l++) {

                    for(int m= 0; m< 4; m++) {

                        if( isSquare( ara[0][j], ara[1][k] , ara[2][l] , ara[3][m] ) ==true) {

                            ans=min(ans, j+k+l+m);
                        }
                    }
                }
            }
        }

        printf("%d\n" ,(ans==1000000)? -1 : ans);


    }
    return 0;

}
