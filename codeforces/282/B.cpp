#include <stdio.h>

int main(){
  int n;scanf("%d",&n);
  for(int d=0,a,g;n--&&scanf("%d%d",&a,&g);)
    putchar(d+a<=500?(d+=a,'A'):(d-=g,'G'));
}