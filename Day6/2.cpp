#include <cstdio>

int n,c,m,l[105],r[105],a[105],old[105][105];
double sums[10005],ans,all;

void DFS(int k)
{
    if (k>m)
    {
        int sum=0;
        for (int i=1;i<=n;i++) sum+=a[i];
        sums[sum]++;
        return;
    }

    for (int i=l[k];i<=r[k];i++)
        for (int j=i-1;j<=r[k];j++)
            for (int b=0;b<c;b++)
            {
                for (int t=i;t<=j;t++)
                {
                    old[k][t]=a[t]; a[t]=a[t]*b%c;
                }
                DFS(k+1);
                for (int t=i;t<=j;t++)
                    a[t]=old[k][t];
            }

    return;
}

int main()
{
    //freopen("2467.in","r",stdin);
    //freopen("2467.out","w",stdout);

    scanf("%d%d%d",&n,&c,&m);

    for (int i=1;i<=m;i++)
        scanf("%d%d",&l[i],&r[i]);

    for (int i=1;i<=n;i++) a[i]=1;
    DFS(1);

    for (int i=0;i<=10000;i++) all+=sums[i];
    for (int i=0;i<=10000;i++)
        ans+=(double)i*(sums[i]/all);
    printf("%.3lf",ans);

    return 0;
}
