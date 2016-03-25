#include <stdio.h>
#include <math.h>

int main()
{
  long long int b,n,k;
  scanf("%I64d%I64d", &n, &k);
  b = ceil(n*1.0 /2);

  if(k <= b)
    printf("%I64d\n", 2 * k - 1);
  else
  {
    printf("%I64d\n", 2*(k - b));
  }
 return 0;
}
