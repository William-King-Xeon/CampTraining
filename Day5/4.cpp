#include <cstdio>

int n;

int main()
{
    freopen("2466.in","r",stdin);
    freopen("2466.out","w",stdout);

    scanf("%d",&n);

    for (int i=1,x,y;i<=n;i++)
    {
        scanf("%d%d",&x,&y);

        int ans=0;
        while (x!=y)
        {
            ans++;
            if (y<x) { int t=x;x=y;y=t; }
            y/=2;
        }

        printf("%d\n",ans);
    }

    return 0;
}
