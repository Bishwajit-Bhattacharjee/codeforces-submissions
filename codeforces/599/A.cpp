#include <bits/stdc++.h>

using namespace std;

int main()
{
    int d1,d2,d3;
    int ans1, ans2, ans;
    scanf("%d %d %d",&d1,&d2,&d3);
    ans1 = 2*d1+2*d2;
    ans2 = d1 +d2+d3;
    int ans3 = d1 + d3 + d3 + d1;
    int ans4 = 2*d2 + 2* d3;
    ans = min(ans1, min(ans2, min(ans3, ans4)));

    printf("%d\n", ans);
    return 0;
}
