#include <cstdio>
#include <cstring>

#define eps 1e-9

int k,n,T,i,j,c,K,x,y,mx,cnt[105];
double g[105][105],f[105][105],ans;

int main()
{
	freopen("paint.in", "r", stdin);
	freopen("paint.out", "w", stdout);
	g[0][0] = 1;
	for (i=0; i<100; ++i)
	for (j=0; j<=i; ++j)
	{
		g[i+1][j] += g[i][j]/2.0;
		g[i+1][j+1] += g[i][j]/2.0;
	}
	scanf("%d%d%d", &n, &c, &K);
	mx = 0;
	memset(cnt, 0, sizeof cnt);
	for (i=1; i<=K; ++i)
	{
		scanf("%d%d", &x, &y);
		for (j=x; j<=y; ++j)
		{
			++cnt[j];
			if (cnt[j] > mx) mx = cnt[j];
		}
	}
	memset(f, 0, sizeof f);
	f[0][1] = 1;
	for (i=0; i<mx; ++i)
	for (j=0; j<c; ++j)
	if (f[i][j] > eps)
	for (k=0; k<c; ++k) f[i+1][j*k%c] += f[i][j]/c;
	ans = 0;
	for (i=1; i<=n; ++i)
	for (j=0; j<=cnt[i]; ++j)
	for (k=0; k<c; ++k) ans += g[cnt[i]][j]*f[j][k]*k;
	printf("%.3lf\n", ans);
	return 0;
}
