#include <cstdio>
#define SQR(x) (x*x)

int n,x[1005],y[1005];

int main()
{
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);

    int ans=0;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            for (int k=1;k<=n;k++)
                if (i!=j && j!=k && i!=k)
                    if (SQR(x[i]-x[j])+SQR(y[i]-y[j])==SQR(x[j]-x[k])+SQR(y[j]-y[k]))
                        ans++;

    printf("%d\n",ans);

    return 0;
}
