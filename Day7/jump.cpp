#include <cstdio>

int n,q,father[100005],letter[100005],k[100005];
char ch;

int main()
{
    freopen("2489.in","r",stdin);
    freopen("2489.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<n;i++)
    {
        scanf("\n%d %c %d",&father[i+1],&ch,&k[i+1]);
        letter[i+1]=ch-'a';
    }

    letter[1]=-1; k[1]=0;

    scanf("%d",&q);

    for (int i=1,u,v,t;i<=q;i++)
    {
        scanf("%d%d%d",&u,&v,&t);
        int uc=0,vc=0;
        while (uc==vc && u!=v && u!=0 && v!=0)
        {
            uc=(letter[u]+k[u]*t)%26,u=father[u];
            vc=(letter[v]+k[v]*t)%26,v=father[v];
        }
        if (uc<vc) printf("<\n"); else
            if (uc==vc) printf("=\n"); else
                printf(">\n");
    }

    return 0;
}
