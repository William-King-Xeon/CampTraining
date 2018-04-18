#include <cstdio>
#include <cstring>
#include <map>
#include <iostream>

using namespace std;

#define clean(x,v) (memset(x,v,sizeof(x)))

int n,m,r,order[100005],f[100005][25],head[100005],root[100005],
	cur,times,step;
string stra[100005],strb[100005],name[100005],x,y;

map <string,int> num;

struct EDGE
{
	int t,n;
} edge[100005];

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
	for (int i=20;i>=0;i--)
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
	Init();

	scanf("%d",&n);

	int names=0;
	for (int i=1;i<=n;i++)
	{
		cin >> stra[i] >> strb[i];
		if (num[stra[i]]==0) { num[stra[i]]=++names;name[names]=stra[i]; }
		if (num[strb[i]]==0) { num[strb[i]]=++names;name[names]=strb[i]; }
		AddEdge(num[stra[i]],num[strb[i]]);
	}

	DFS(1,0);
	for (int i=1;i<=20;i++)
		for (int j=1;j<=names;j++)
	    	f[j][i]=f[f[j][i-1]][i-1];

	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		cin >> x >> y;
		cout << name[ LCA(num[x],num[y]) ].c_str() << endl;
	}

	return 0;
}
