#include <cstdio>
#include <algorithm>

using namespace std;

struct CHESS
{
	int x,y,num;
} chess[100005];

int n,f[100005],tree[160005];

bool Compare(CHESS a,CHESS b)
{
	if (a.x!=b.x) return a.x<b.x;
	return a.y<b.y;
}

void Change(int cur,int l,int r,int x)
{
	if (r<x||l>x) return;
	if (l==x&&r==x)
	{
		tree[cur]++;
		return;
	}
	Change(cur*2,l,(l+r)/2,x);
	Change(cur*2+1,(l+r)/2+1,r,x);
	tree[cur]=tree[cur*2]+tree[cur*2+1];
	return;
}

int Query(int cur,int l,int r,int s,int t)
{
	if (t<l||s>r) return 0;
	if (s<=l&&r<=t) return tree[cur];
	return Query(cur*2,l,(l+r)/2,s,t)+
           Query(cur*2+1,(l+r)/2+1,r,s,t);
}

int main()
{
	freopen("1670.in","r",stdin);
	freopen("1670.out","w",stdout);

	scanf("%d",&n);

	for (int i=1;i<=n;i++)
	{
		scanf("%d%d",&chess[i].x,&chess[i].y);
		chess[i].x++,chess[i].y++;
		chess[i].num=i;
	}

	sort(chess+1,chess+1+n,Compare);

	for (int i=1;i<=n;i++)
	{
		f[chess[i].num]=Query(1,1,40005,1,chess[i].y);
		Change(1,1,40005,chess[i].y);
	}

	for (int i=1;i<=n;i++) printf("%d\n",f[i]);

	return 0;
}
