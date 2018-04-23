#include <cstdio>
#include <cstring>

#define MAX(a,b) (a>b?a:b)
#define MIN(a,b) (a<b?a:b)

struct EDGE
{
	int t,n;
} edge[100005];

int cur=-1,last[100005],
    cnt,DFN[100005],LOW[100005],Stack[100005],Instack[100005],Belong[100005],Top,Index,
    n,edges,a[100005],b[100005],In[100005],Out[100005];

void AddEdge(int u,int v)
{
	cur++;
	edge[cur].t=v;
	edge[cur].n=last[u];
	last[u]=cur;
    return;
}

void Tarjan(int x)
{
	DFN[x]=LOW[x]=++Index;
	Instack[x]=true;
	Stack[++Top]=x;
	int tmp=last[x];
	while (tmp!=-1)
	{
		int target=edge[tmp].t;
		if (!DFN[target])
        {
            Tarjan(target);
            LOW[x]=MIN(LOW[x],LOW[target]);
        }
        else if (Instack[target]&&LOW[x]>DFN[target]) LOW[x]=DFN[target];
        tmp=edge[tmp].n;
    }
    if (LOW[x]==DFN[x])
    {
        cnt++;
        while (Stack[Top+1]!=x)
        {
            Belong[Stack[Top]]=cnt;
            Instack[Stack[Top--]]=0;
        }
    }
    return;
}

int main()
{
	memset(last,-1,sizeof(last));

	scanf("%d",&n);

	for (int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
		while (x!=0)
		{
			edges++;
			a[edges]=i;
			AddEdge(a[edges],b[edges]=x);
            scanf("%d",&x);
		}
    }

	for (int i=1;i<=n;i++)
		if (!DFN[i]) Tarjan(i);

	for (int i=1;i<=edges;i++)
		if (Belong[a[i]]!=Belong[b[i]])
		{
			In[Belong[b[i]]]++;
			Out[Belong[a[i]]]++;
		}

	int in=0,out=0;
	for (int i=1;i<=cnt;i++)
	{
		if (!In[i]) in++;
		if (!Out[i]) out++;
	}

	if (cnt==1) printf("1\n0\n");
        else printf("%d\n%d",in,MAX(in,out));

	return 0;
}
