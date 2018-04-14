#include <cstdio>
#include <cstring>

#define clean(x,v) (memset(x,v,sizeof(x)))

int T,n,m,x,y,r,order[100005],f[100005][21],head[100005],dis[100005];
int cur,times,step;

struct EDGE
{
	int t,l,n;
} edge[100005];

void AddEdge(int u,int v,int w)
{
	cur++;
	edge[cur].t=v;
	edge[cur].l=w;
	edge[cur].n=head[u];
	head[u]=cur;
}

void DFS(int cur,int father)
{
	order[cur]=++times;
	f[cur][0]=father;
	for (int tmp=head[cur];tmp!=-1;tmp=edge[tmp].n)
	{
		int target=edge[tmp].t;
		if (target==father) continue;
		dis[target]=dis[cur]+edge[tmp].l;
		DFS(target,cur);
	}
	return;
}

int LCA(int x,int y)
{
	if (order[x]<order[y]) { int t=x;x=y;y=t; }
	for (int i=14;i>=0;i--)
		if (order[f[x][i]]>order[y]&&order[f[x][i]]!=0) x=f[x][i];
	if (x==y) return x;
	return f[x][0];
}

void Init()
{
	cur=times=0;
	clean(edge,0);
	clean(head,-1);
	clean(f,0);
	clean(order,0);
	return;
}
int main()
{
	scanf("%d",&T);
	while (T--)
	{
		Init();

		scanf("%d%d",&n,&m);
		for (int i=1,a,b,c;i<n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			AddEdge(a,b,c);
			AddEdge(b,a,c);
		}

		DFS(1,1);

		for (int i=1;i<=14;i++)
			for (int j=1;j<=n;j++)
		    	f[j][i]=f[f[j][i-1]][i-1];

		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&x,&y);
			int lca=LCA(x,y);
			printf("%d\n",dis[x]+dis[y]-2*dis[lca]);
		}
	}
	return 0;
}
