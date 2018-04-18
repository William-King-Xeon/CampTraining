#include <cstdio>
#include <cmath>
#define INF 1000000000

int n,t,s,e,I,dis[1005][1005];

int DFS(int s,int e,int n)
{
    if (n==1) return dis[s][e];
    int ret=INF;
    if (n&1)
    {
        for (int i=1,cur;i<=I;i++)
            if (i!=s && i!=e && (cur=(DFS(s,i,n-1)+dis[i][e]))<ret) ret=cur;
    }
    else
    {
        for (int i=1,cur;i<=I;i++)
            if (i!=s && i!=e && (cur=DFS(s,i,n/2)+DFS(i,e,n/2))<ret) ret=cur;
    }
    return ret;
}

int main()
{
    for (int i=0;i<1005;i++)
        for (int j=0;j<1005;j++)
            dis[i][j]=INF;

    scanf("%d%d%d%d",&n,&t,&s,&e);

    for (int i=1,x,y,len;i<=t;i++)
    {
        scanf("%d%d%d",&len,&x,&y);
        if (x>I) I=x;if (y>I) I=y;
        dis[x][y]=dis[y][x]=len;
    }

    printf("%d\n",DFS(s,e,n));

    return 0;
}
