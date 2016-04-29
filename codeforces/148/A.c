#include <stdio.h>
void work(char ara[], int x,int d)
{
    int i;
    for(i=1;i*x<=d;i++)
    {
        if(ara[i*x]=='0')
        ara[i*x] = '1';

    }
}
int main()
{
  int k,l,m, n,d,i;
  char ara[100001];
  for(i=0;i<100001;i++)
    ara[i]='0';

  scanf("%d %d %d %d %d", &k,&l,&m,&n,&d);
  work(ara,k,d);
  work(ara,l,d);
  work(ara,m,d);
  work(ara,n,d);
  int count = 0;
  for(i=1;i<=d;i++)
  {
      if(ara[i]=='1')
          count++;
  }
  printf("%d\n",count);

return 0;
}
