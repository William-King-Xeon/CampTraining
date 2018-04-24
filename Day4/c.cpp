#include <cstdio>
#include <cmath>
#define INF 1000000000

int cur=-1,n,t,s,e,I,f[1001][1001][21],steps[1000005];

int DFS(int s,int e,int n)
{
    int step=steps[n];

    if (f[s][e][step]!=INF || n==1)
        return f[s][e][step];
    if (n&1)
    {
        int ret=INF;
        for (int i=1,cur;i<=I;i++)
            if (i!=s && i!=e && (cur=DFS(s,i,n-1))+f[s][i][0]<ret) ret=cur;
        return ret;
    }
    else
    {
        for (int i=1,cur;i<=I;i++)
            if (i!=s && i!=e && (cur=DFS(s,i,n/2)+DFS(i,e,n/2))<f[s][e][step]) f[s][e][step]=cur;
        return f[s][e][step];
    }
}

int main()
{
    for (int i=0;i<1001;i++)
        for (int j=0;j<1001;j++)
            for (int k=0;k<21;k++)
                f[i][j][k]=INF;

    scanf("%d%d%d%d",&n,&t,&s,&e);

    int tmp=n,stepnum=0;
    while (tmp!=1) { tmp/=2;stepnum++; }
    tmp=n;
    while (tmp)
    {
        steps[tmp]=stepnum;
        stepnum--,tmp/=2;
    }

    for (int i=1,x,y,len;i<=t;i++)
    {
        scanf("%d%d%d",&len,&x,&y);
        if (x>I) I=x;if (y>I) I=y;
        f[x][y][0]=f[y][x][0]=len;
    }

    printf("%d\n",DFS(s,e,n));

    return 0;
}
