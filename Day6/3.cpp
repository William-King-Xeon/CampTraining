#include <cstdio>
#define INF 100000000

int n,m,dis[25][25],set1[1000005],set2[1000005],setn1,setn2,f[25][1050000],g[25][1050000];

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
    scanf("%d%d",&n,&m);

    for (int i=0;i<(1<<n);i++)
        if ((i&1) && (CntOne(i)<=n/2+1) && (CntOne(i)>1)) set1[setn1++]=i;

    for (int i=0;i<(1<<n);i++)
        if ((i&(1<<(n-1))) && (CntOne(i)<=(n+1)/2+1) && (CntOne(i)>1)) set2[setn2++]=i;

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

    for (int i=0;i<n;i++)
        for (int j=0;j<setn1;j++)
            f[i][set1[j]]=INF;

    f[0][1]=0;

    for (int i=0;i<setn1;i++)
        for (int e=1;e<n;e++)
            if (set1[i]&(1<<e))
                for (int last=0;last<n;last++)
                    if (set1[i]&(1<<last))
                        if (last!=e)
                            if (f[last][set1[i]-(1<<e)]+dis[last][e]<f[e][set1[i]])
                                f[e][set1[i]]=f[last][set1[i]-(1<<e)]+dis[last][e];

    for (int i=0;i<n;i++)
        for (int j=0;j<setn2;j++)
            g[i][set2[j]]=INF;

    g[n-1][1<<(n-1)]=0;

    for (int i=0;i<setn2;i++)
        for (int s=0;s<n-1;s++)
            if (set2[i]&(1<<s))
                for (int last=0;last<n;last++)
                    if (set2[i]&(1<<last))
                        if (last!=s)
                            if (g[last][set2[i]-(1<<s)]+dis[s][last]<g[s][set2[i]])
                                g[s][set2[i]]=g[last][set2[i]-(1<<s)]+dis[s][last];

    int ans=INF;
    for (int seti=0;seti<setn1;seti++)
    {
        int fset=set1[seti];
        int gset=((1<<n)-1)^fset;
        if (CntOne(fset)==n/2)
        {
            int a=INF,b=INF;
            for (int i=1;i<n-1;i++)
                if (fset&(1<<i))
                    for (int j=1;j<n-1;j++)
                        if ((gset&(1<<j)) && i!=j)
                            if (f[i][fset|1]+dis[i][j]+g[j][gset|(1<<(n-1))]<a)
                                a=f[i][fset|1]+dis[i][j]+g[j][gset|(1<<(n-1))];
            for (int i=1;i<n-1;i++)
                if (fset&(1<<i))
                    for (int j=1;j<n-1;j++)
                        if ((gset&(1<<j)) && i!=j)
                            if (g[i][fset|(1<<(n-1))]+dis[i][j]+f[j][gset|1]<b)
                                b=g[i][fset|(1<<(n-1))]+dis[i][j]+f[j][gset|1];
            if (a+b<ans)
            {
                printf("%d %d\n",a,b);
                ans=a+b;
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}
