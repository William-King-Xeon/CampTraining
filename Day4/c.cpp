#include <cstdio>
#include <cmath>
#define INF 1000000000

int cur=-1,n,t,s,e,f[105][105][25],steps[1000005];

int DFS(int s,int e,int n)
{
    int step=steps[n];

    if (f[s][e][step]!=INF || n==1)
    {
        printf("%d %d %d F:%d\n",s,e,n,f[s][e][step]);
        return f[s][e][step];
    }
    if (n&1)
    {
        int ret=INF;
        for (int i=1,cur;i<=t;i++)
            if (i!=s && i!=e && (cur=DFS(s,i,n-1))+f[s][i][0]<ret) ret=cur;
        printf("%d %d %d F:%d\n",s,e,n,ret);
        return ret;
    }
    else
    {
        for (int i=1,cur;i<=t;i++)
            if (i!=s && i!=e && (cur=DFS(s,i,n/2)+DFS(i,e,n/2))<f[s][e][step]) f[s][e][step]=cur;
        printf("%d %d %d F:%d\n",s,e,n,f[s][e][step]);
        return f[s][e][step];
    }
}

int main()
{
    for (int i=0;i<105;i++)
        for (int j=0;j<105;j++)
            for (int k=0;k<25;k++)
                f[i][j][k]=INF;

    scanf("%d%d%d%d",&n,&t,&s,&e);

    int tmp=n,stepnum=0;
    while (tmp!=1) { tmp/=2;stepnum++; }
    tmp=n;
    for (int i=n;i>=0;i--)
    {
        if (tmp/2==i) stepnum--,tmp/=2;
        steps[i]=stepnum;
    }

    for (int i=1,x,y,len;i<=t;i++)
    {
        scanf("%d%d%d",&len,&x,&y);
        f[x][y][0]=f[y][x][0]=len;
    }

    printf("%d\n",DFS(s,e,n));

    return 0;
}
