#include <cstdio>
#include <cstring>
#include <queue>

#define MIN(a,b) (a<b?a:b)
#define clean(x,y) (memset(x,y,sizeof(x)))

struct EDGE
{
	int t,n;
} edge[8005];

int DFN[8005],LOW[8005],Stack[8005],InStack[8005],Belong[8005],a[8005],b[8005],last[8005],
    T,n,m,InDegree[8005],
    Index,Top,Bcnt,edges;

std::queue <int> q;

void AddEdge(int u,int v)
{
	edges++;
	edge[edges].t=v;
	edge[edges].n=last[u];
	last[u]=edges;
    return;
}

void Tarjan(int x)
{
	DFN[x]=LOW[x]=++Index;
	InStack[x]=true;
	Stack[++Top]=x;

	for (int tmp=last[x];tmp!=-1;tmp=edge[tmp].n)
	{
		int target=edge[tmp].t;
		if (!DFN[target])
        {
            Tarjan(target);
            LOW[x]=MIN(LOW[x],LOW[target]);
        }
        else if (InStack[target]) LOW[x]=MIN(LOW[x],DFN[target]);
    }

    if (LOW[x]==DFN[x])
    {
        Bcnt++;
        while (Stack[Top+1]!=x)
        {
            Belong[Stack[Top]]=Bcnt;
            InStack[Stack[Top--]]=0;
        }
    }

    return;
}

bool Top_Sort()
{
    clean(InDegree,0);

	for (int i=1;i<=Bcnt;i++)
		for (int tmp=last[i];tmp!=-1;tmp=edge[tmp].n)
			InDegree[edge[tmp].t]++;

    while (!q.empty()) q.pop();

	int cnt=0;
	for (int i=1;i<=Bcnt;i++)
		if (!InDegree[i]) q.push(i),cnt++;
	if (cnt>1) return false;

	while (!q.empty())
	{
		int cur=q.front();

        cnt=0;
		for (int tmp=last[cur];tmp!=-1;tmp=edge[tmp].n)
		{
			int target=edge[tmp].t;
			InDegree[target]--;
			if (InDegree[target]==0) q.push(target),cnt++;
		}
		if (cnt>1) return false;

        q.pop();
	}

	return true;
}
void Init()
{
    edges=-1;
    clean(last,-1);
	clean(edge,0);
	clean(DFN,0);
	clean(LOW,0);
	clean(Belong,0);
	clean(InStack,0);
	clean(Stack,0);
	Top=Bcnt=Index=0;
}
int main()
{
	scanf("%d",&T);

	while (T--)
	{
        Init();

		scanf("%d%d",&n,&m);
		for (int i=1;i<=m;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			AddEdge(a[i],b[i]);
		}

		for (int i=1;i<=n;i++)
			if (!DFN[i]) Tarjan(i);

        edges=-1;
        clean(last,-1);
    	clean(edge,0);

		for (int i=1;i<=m;i++)
			if (Belong[a[i]]!=Belong[b[i]])
				AddEdge(Belong[a[i]],Belong[b[i]]);

		if (Top_Sort()) printf("Yes\n");
            else printf("No\n");
	}

	return 0;
}
