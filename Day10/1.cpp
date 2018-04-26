#include <cstdio>

int n,father[100005],cnt[100005],q,U,V,
    from[100005],to[100005];
char cmd[1];

int Compress(int x)
{
    if (cnt[x]<=1) return x;
    return father[x]=Compress(father[x]);
}

void Add(int u,int v)
{
    if (u==v) return;
    if (u<v) { int t=u;u=v;v=t; }
    cnt[u]++;
    from[u]=U,to[u]=V;
    Compress(u);
    Add(father[u],v);
    return;
}

int main()
{
    freopen("2490.in","r",stdin);
    freopen("2490.out","w",stdout);

    scanf("%d",&n);
    printf("%d\n",n);

    for (int i=1;i<n;i++) scanf("%d",&father[i]);

    scanf("%d",&q);

    while (q--)
    {
        scanf("%s",cmd);
        if (cmd[0]=='R')
        {
            scanf("%d%d",&U,&V);
            if (U>V) { int t=U;U=V;V=t; }
            Add(U,V);
        } else
        {
            scanf("%d",&V);
            if (cnt[V]==0) printf("Not yet\n");
                else if (cnt[V]==1) printf("%d %d\n",from[V],to[V]);
                    else printf("Many times\n");
        }
    }

    return 0;
}
