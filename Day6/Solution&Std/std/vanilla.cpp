#include <cstdio>
#define inf 1000000007
#define N 24
int a[N][N],d[N][N],f[2][N][1050000],e[N],cnt[1050000],n,n1,n2,x,y,z,i,j,m,k,q,ans,sta;

int main()
{
	freopen("vanilla.in", "r", stdin);
	freopen("vanilla.out", "w", stdout);
	e[0] = 1;
	//预处理2^i
	for (i=1; i<=22; ++i) e[i] = e[i-1]<<1;
    //预处理每个二进制数中有几个1
	for (i=0; i<e[20]; ++i)
	for (x=i; x!=0; x>>=1) cnt[i] += x&1;

	scanf("%d%d", &n, &m);
	for (i=1; i<=n; ++i)
	for (j=1; j<=n; ++j) d[i][j] = inf*(i!=j);
	for (i=1; i<=m; ++i)
	{
		scanf("%d%d%d", &x, &y, &z);
		++x;
		++y;
		if (z<d[x][y]) d[x][y] = d[y][x] = z;
	}
	
	// floyd求两两最短路
	for (k=1; k<=n; ++k)
	for (i=1; i<=n; ++i)
	for (j=1; j<=n; ++j)
	if (d[i][k]+d[k][j] < d[i][j]) d[i][j] = d[i][k]+d[k][j];

    if (n == 3)
    {
        printf("%d\n", (d[1][2]+d[2][3])*2);
        return 0;
    }
    
    n1 = (n-2)/2;
    n2 = n-2-n1;
	//求从家、花店开始，走到点i，经过的点为j的最短路
	//q=0：从家开始，q=1：从花店开始
	for (q=0; q<=1; ++q)
	{
		//初始化状态
		for (i=1; i<=n; ++i)
		for (j=0; j<e[n-2]; ++j) f[q][i][j] = inf;
		if (q == 0)
		{
			for (i=2; i<n; ++i) f[q][i][e[i-2]] = d[1][i];
		}
		else
		{
			for (i=2; i<n; ++i) f[q][i][e[i-2]] = d[n][i];
		}
		
		//dp
		for (j=1; j<e[n-2]; ++j)
		if (cnt[j] < n2)
		for (i=2; i<n; ++i)
		if (f[q][i][j] < inf)
		for (k=2; k<n; ++k)
		if (f[q][i][j]+d[i][k] < f[q][k][j|e[k-2]]) f[q][k][j|e[k-2]] = f[q][i][j]+d[i][k];
	}
	
	ans = inf;
	//枚举先走到的一半为sta
	for (sta=0; sta<e[n-2]; ++sta)
	if (cnt[sta] == n1)
	{
		//前半段
		x = inf; //x记录前半段的最短距离
		//枚举前一半中最后一个收割的点是i
		for (i=2; i<n; ++i)
		if (sta&e[i-2])
		//枚举后一半中第一个收割的点是j
		for (j=2; j<n; ++j)
		if (!(sta&e[j-2]))
		if (f[0][i][sta]+d[i][j]+f[1][j][e[n-2]-1-sta] < x) x = f[0][i][sta]+d[i][j]+f[1][j][e[n-2]-1-sta];
		
		
		//后半段
		//枚举前一半中最后一个播种的点是i
		for (i=2; i<n; ++i)
		if (sta&e[i-2])
		//枚举后一半中第一个播种的点是j
		for (j=2; j<n; ++j)
		if (!(sta&e[j-2]))
		if (x+f[1][i][sta]+d[i][j]+f[0][j][e[n-2]-1-sta] < ans) ans = x+f[1][i][sta]+d[i][j]+f[0][j][e[n-2]-1-sta];
	}
	printf("%d\n", ans);
	return 0;
}
