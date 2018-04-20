#include <cstdio>
int n,a[2][40],i,w[2],x,e[40];

void read(int t)
{
	scanf("%d", &x);
	for (w[t]=0; x>0; x>>=1) e[++w[t]] = (x&1);
	for (i=1; i<=w[t]; ++i) a[t][i] = e[w[t]-i+1];
}

int main()
{
	freopen("city.in", "r", stdin);
	freopen("city.out", "w", stdout);
	scanf("%d", &n);
	while (n--)
	{
		read(0);
		read(1);
		a[0][w[0]+1] = 2;
		a[1][w[1]+1] = 3;
		for (i=1; a[0][i]==a[1][i]; ++i);
		--i;
		printf("%d\n", w[0]+w[1]-i*2);
	}
	return 0;
}

