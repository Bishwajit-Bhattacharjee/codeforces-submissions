#include <bits/stdc++.h>

using namespace std;
long long ar[2009][2009],pr[4009],ap[4009];
int main()
{
    long long a,s,d,f,g,h,j,k,l,ans,flag,n,ans1,ans2,row1,row2,col1,col2;
    cin>>n;
    for(a=1;a<=n;a++)
    {
        for(s=1;s<=n;s++)
        {
            int temp;
            scanf("%d",&temp);
            ar[a][s]=temp;
            pr[a+s]+=temp;
            ap[a+n-s-1]+=temp;
        }
    }
    ans1=0;
    ans2=0;
    for(a=1;a<=n;a++)
    {
        for(s=1;s<=n;s++)
        {
            if((a+s)%2)
            {
                if(pr[a+s]+ap[a+n-1-s]-ar[a][s]>=ans1)
                {
                    ans1=pr[a+s]+ap[a+n-1-s]-ar[a][s];
                    row1=a;
                    col1=s;
                }
            }
            else
            {
                if(pr[a+s]+ap[a+n-1-s]-ar[a][s]>=ans2)
                {
                    ans2=pr[a+s]+ap[a+n-1-s]-ar[a][s];
                    row2=a;
                    col2=s;
                }
            }
        }
    }
    cout<<ans1+ans2<<endl<<row1<<" "<<col1<<" "<<row2<<" "<<col2<<endl;
}