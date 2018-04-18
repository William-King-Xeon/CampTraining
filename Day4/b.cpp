#include <cstdio>
#include <cstring>

#define clean(x,v) (memset(x,v,sizeof(x)))

int n,m,x,y,k,order[100005],f[100005][25],sum[100005][25],head[100005];
int cur,times;

struct EDGE
{
	int t,n,l;
} edge[200005];

void AddEdge(int u,int v,int len)
{
	cur++;
	edge[cur].t=v;
	edge[cur].n=head[u];
	edge[cur].l=len;
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
		sum[target][0]=edge[tmp].l;
		DFS(target,cur);
	}
	return;
}

int LCA(int x,int y)
{
	int ret=0;
	if (order[x]<order[y]) { int t=x;x=y;y=t; }

	if (x==y) return 0;
	for (int i=20;i>=0;i--)
		if (order[f[x][i]]>order[y]&&order[f[x][i]]!=0) ret+=sum[x][i],x=f[x][i];
	ret+=sum[x][0],x=f[x][0];
	if (x==y) return ret;

	for (int i=20;i>=0;i--)
		if (order[x]<order[f[y][i]]&&order[f[y][i]]!=0) ret+=sum[y][i],y=f[y][i];
	ret+=sum[y][0],y=f[y][0];
	return ret;
}

void Init()
{
	cur=times=0;
	clean(edge,0);
	clean(head,-1);
	clean(f,0);
	clean(sum,0);
	clean(order,0);
	return;
}

int main()
{
	Init();

	scanf("%d%d",&n,&m);
	for (int i=1,a,b,len;i<=m;i++)
	{
		char ch;
		scanf("%d%d%d %c",&a,&b,&len,&ch);
		AddEdge(a,b,len),
		AddEdge(b,a,len);
	}

	DFS(1,0);

	for (int i=1;i<=20;i++)
		for (int j=1;j<=n;j++)
	    	f[j][i]=f[f[j][i-1]][i-1],
			sum[j][i]=sum[j][i-1]+sum[f[j][i-1]][i-1];

	scanf("%d",&k);
	while (k--)
	{
		scanf("%d%d",&x,&y);
		printf("%d\n",LCA(x,y));
	}

	return 0;
}
