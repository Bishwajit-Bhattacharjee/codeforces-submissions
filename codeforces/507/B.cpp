#include <bits/stdc++.h>

#define char_to_num(ch) (ch-'0')
using namespace std;
int main()
{
   long long int x, y ,x1, y1, r, step;
    scanf("%I64d%I64d%I64d%I64d%I64d", &r, &x, &y, &x1, &y1);
  //  long long int h = ((x-x1)*(x-x1) + (y-y1)*(y-y1));
    double d = sqrt(1.0*((x-x1)*(x-x1) + (y-y1)*(y-y1)));
    step = ceil(d / (2 *  r));

    printf("%I64d\n", step);

	return 0;
}
