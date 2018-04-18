#include <cstdio>
#include <iostream>

using namespace std;

int n,T,a[100005];

int main()
{
    //freopen("c.out","w",stdout);

    scanf("%d",&T);

    for (int t=1;t<=T;t++)
    {
        scanf("%d",&n);

        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);

        int sum=0,maxsum=-2147483648,start=1,ms,me;

        for (int i=1;i<=n;i++)
        {
            sum+=a[i];
            if (sum>maxsum)
            {
                maxsum=sum;
                ms=start,me=i;
            }
            if (sum<0)
            {
                start=i+1;
                sum=0;
            }
        }

        printf("Case %d:\n%d %d %d\n",t,maxsum,ms,me);
        if (t!=T) printf("\n");
    }

    return 0;
}
