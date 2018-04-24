#include <cstdio>
#include <cstring>
#include <queue>

#define MIN(a,b) (a<b?a:b)
#define clean(x,y) (memset(x,y,sizeof(x)))

struct EDGE
{
	int t,n;
} edge[40005];

int edges,last[205],
    T,n,m,InDegree[205],result[205];

std::priority_queue <int> q;

void Init()
{
    edges=-1;
    clean(last,-1);
	clean(edge,0);
	clean(InDegree,0);
	clean(result,0);
	return;
}

void AddEdge(int u,int v)
{
	edges++;
	edge[edges].t=v;
	edge[edges].n=last[u];
	last[u]=edges;
    return;
}

bool Top_Sort()
{
    while (!q.empty()) q.pop();

	for (int i=1;i<=n;i++)
		if (!InDegree[i]) q.push(i);

	int rank=n;

	while (!q.empty())
	{
		int cur=q.top(); q.pop();
		result[cur]=rank--;

		for (int tmp=last[cur];tmp!=-1;tmp=edge[tmp].n)
		{
			int target=edge[tmp].t;
			InDegree[target]--;
			if (!InDegree[target]) q.push(target);
		}
	}

	return (rank==0);
}

int main()
{
	scanf("%d",&T);

	while (T--)
	{
        Init();

		scanf("%d%d",&n,&m);
		for (int i=1,a,b;i<=m;i++)
		{
			scanf("%d%d",&a,&b);
			AddEdge(b,a);
			InDegree[a]++;
		}

		if (Top_Sort())
			for (int i=1;i<=n;i++) printf("%d ",result[i]);
        else printf("-1");
		printf("\n");
	}

	return 0;
}
