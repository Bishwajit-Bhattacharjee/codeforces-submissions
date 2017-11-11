#include <algorithm>
#include <stdio.h>
#define  inf	   1 << 30
using	 namespace std;

int h,a,d,ans=inf;
int hp0,atk0,def0;
int hp2,atk2,def2;

int main()
{
  scanf("%d%d%d",&hp0,&atk0,&def0);
  scanf("%d%d%d",&hp2,&atk2,&def2);
  scanf("%d%d%d",&h,&a,&d);
  for(int atk1=atk0 ; atk1<=200 ; atk1++)
    for(int def1=def0 ; def1<=100 ; def1++)
      if(atk1>def2)
      {
	    int dmg1=atk1-def2;
	    int dmg2=max(atk2-def1,0);
	    int t=hp2/dmg1+!(!(hp2%dmg1));
	    int hp1=max(hp0,t*dmg2+1);
	    ans=min(ans,(hp1-hp0)*h+(atk1-atk0)*a+(def1-def0)*d);
	  }
  printf("%d\n",ans);
  return 0;
}