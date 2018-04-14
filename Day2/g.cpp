#include <cstdio>
#include <cstring>

#define clean(x,v) (memset(x,v,sizeof(x)))

int T,n,x,y,r,order[10005],f[10005][21],head[10005],root[10005];
int cur,times,step;

struct EDGE
{
	int t,n;
} edge[10005];

void AddEdge(int u,int v)
{
	cur++;
	edge[cur].t=v;
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
	clean(root,true);
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

		scanf("%d",&n);
		for (int i=1,a,b;i<n;i++)
		{
			scanf("%d%d",&a,&b);
			AddEdge(a,b);
			root[b]=false;
		}

		scanf("%d%d",&x,&y);
		for (int i=1;i<=n;i++)
			if (root[i]) { r=i;break;}
		DFS(r,r);

		for (int i=1;i<=14;i++)
			for (int j=1;j<=n;j++)
		    	f[j][i]=f[f[j][i-1]][i-1];

		printf("%d\n",LCA(x,y));
	}
	return 0;
}
