#include <cstdio>

int T,n,m,k,map[20][20],a[20];
bool visit[20][20];

int main()
{
    freopen("2465.in","r",stdin);
    freopen("2465.out","w",stdout);

    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=m;j++)
                scanf("%d",&map[i][j]);
        for (int i=1;i<=k;i++) scanf("%d",&a[k]);

        bool done;
        for (int i=1;i<=k;i++)
        {
            done=false;
            for (int x1=1;x1<=n;x1++)
                if (!done)
                for (int y1=1;y1<=m;y1++)
                    if (!done)
                    for (int x2=x1;x2<=n;x2++)
                        if (!done)
                        for (int y2=y1;y2<=m;y2++)
                            if (!done)
                            {
                                int sum=0;
                                bool ok=false;
                                for (int k=x1;k<=x2;k++)
                                    for (int l=y1;l<=y2;l++)
                                    {
                                        if (visit[k][l]) { ok=true;break; }
                                        sum+=map[k][l];
                                    }
                                if (!ok || sum!=a[i]) break;
                                done=true;
                                for (int k=x1;k<=x2;k++)
                                    for (int l=y1;l<=y2;l++)
                                        visit[k][l]=true;
                            }
            if (!done) break;
        }
        if (!done) printf("no\n"); else printf("yes\n");
    }

    return 0;
}
