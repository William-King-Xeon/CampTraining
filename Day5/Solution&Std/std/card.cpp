#include <cstdio>
#include <algorithm>

#define inf 1000000007
#define N 500055

int n,i,x,y,top[N*2],bot[N*2],ans,hf,lst,p;

struct T
{
	int v, f;
};

T a[N*2];

bool cmpv(const T &a, const T &b)
{
	return a.v < b.v;
}

bool cmpf(const T &a, const T &b)
{
	return a.f < b.f;
}

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	scanf("%d",&n);
	for (i=1; i<=n; ++i)
	{
		scanf("%d%d", &a[i*2-1].v, &a[i*2].v);
		a[i*2-1].f = i*2-1;
		a[i*2].f = i*2;
	}
	std::sort(a+1, a+n*2+1, cmpv);
	lst = -1;
	for (i=1; i<=n*2; ++i)
	{
		p += (lst!=a[i].v);
		lst = a[i].v;
		a[i].v = p;
	}
	std::sort(a+1, a+n*2+1, cmpf);
	
	for (i=1; i<=n; ++i)
	{
		x = a[i*2-1].v;
		y = a[i*2].v;
		++top[x];
		if (x!=y) ++bot[y];
	}
	hf = (n+1)/2;
	ans = inf;
	for (i=1; i<=p; ++i)
	{
		if (top[i]+bot[i] < hf) continue;
		if (top[i] >= hf)
		{
			ans = 0;
			break;
		}
		if (hf-top[i] < ans) ans = hf-top[i];
	}
	if (ans == inf) printf("Impossible\n"); else printf("%d\n",ans);
	return 0;
}
