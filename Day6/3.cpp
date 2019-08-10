#include <cstdio>
#define INF 10000000000

int n,m;
long long dis[25][25],f[25][1050000],g[25][1050000];

int CntOne(int x)
{
    int ret=0;
    while (x)
    {
        if (x&1) ret++;
        x>>=1;
    }
    return ret;
}

int main()
{
    //freopen("2468.in","r",stdin);
    //freopen("2468.out","w",stdout);

    scanf("%d%d",&n,&m);

    int N=n-2;

    for (int i=0;i<n;i++)
        for (int j=0;j<n;j++)
            dis[i][j]=INF;

    for (int i=1,x,y,z;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y]=dis[y][x]=z;
    }

    for (int s=0;s<n;s++)
        for (int mid=0;mid<n;mid++)
            for (int e=0;e<n;e++)
                if (dis[s][mid]+dis[mid][e]<dis[s][e])
                    dis[s][e]=dis[s][mid]+dis[mid][e];

    if (n==3)
    {
        printf("%lld\n",(dis[0][1]+dis[1][2])*2);
        return 0;
    }

    for (int i=0;i<N;i++)
        for (int j=0;j<(1<<N);j++)
            f[i][j]=INF;

    for (int i=0;i<N;i++)
        f[i][1<<i]=dis[0][i+1];

    for (int set=0;set<(1<<N);set++)
        if (CntOne(set)>1)
            for (int e=0;e<N;e++)
                if (set&(1<<e))
                    for (int last=0;last<N;last++)
                        if (set&(1<<last))
                            if (last!=e)
                                if (f[last][set-(1<<e)]+dis[last+1][e+1]<f[e][set])
                                    f[e][set]=f[last][set-(1<<e)]+dis[last+1][e+1];

    for (int i=0;i<N;i++)
        for (int j=0;j<(1<<N);j++)
            g[i][j]=INF;

    for (int i=0;i<N;i++)
        g[i][1<<i]=dis[i+1][n-1];

    for (int set=0;set<(1<<N);set++)
        if (CntOne(set)>1)
            for (int s=0;s<N;s++)
                if (set&(1<<s))
                    for (int last=0;last<N;last++)
                        if (set&(1<<last))
                            if (last!=s)
                                if (g[last][set-(1<<s)]+dis[s+1][last+1]<g[s][set])
                                    g[s][set]=g[last][set-(1<<s)]+dis[s+1][last+1];

    long long ans=INF;
    for (int fset=0;fset<(1<<N);fset++)
        if (CntOne(fset)==N/2)
        {
            int gset=((1<<N)-1)^fset;
			long long  a=INF,b=INF;
            for (int i=0;i<N;i++)
                if (fset&(1<<i))
                    for (int j=0;j<N;j++)
                        if ((gset&(1<<j)))
                        {
                            if (f[i][fset]+dis[i+1][j+1]+g[j][gset]<a)
                                a=f[i][fset]+dis[i+1][j+1]+g[j][gset];
                            if (g[i][fset]+dis[i+1][j+1]+f[j][gset]<b)
                                b=g[i][fset]+dis[i+1][j+1]+f[j][gset];
                        }
            if (a+b<ans) ans=a+b;
        }
    printf("%lld\n",ans);

    return 0;
}
