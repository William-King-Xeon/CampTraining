#include <cstdio>
#include <list>

#define MAXK 15
#define N 11

struct Quad
{
	int a, b, c, d;
	Quad(int _a, int _b, int _c, int _d): a(_a), b(_b), c(_c), d(_d) {}
};

std::list<Quad> lf, lfx, lfy;
char f[N][N][N][1<<MAXK],fx[N][N][N][1010],fy[N][N][N][1010];
int sumx[N][N][N],sumy[N][N][N],suma[1<<MAXK],bg[1<<MAXK],ed[1<<MAXK],c[15000000],e[MAXK+1],a[20],
    n,m,K,i,j,l,r,T,sta,nc,w;

/*
求：以j1为左边界、j2为右边界、i1为上边界的矩形中，下边界为多少的矩形
重量和是w。如果不存在则返回-1
用二分求
*/
int calcx(int j1, int j2, int i1, int w)
{
	// fx[j1][j2][i1][w]用于记录该子问题有没有被求结果
	// 已求结果则直接返回结果
	if (fx[j1][j2][i1][w] != 0) return fx[j1][j2][i1][w];
	// 未求结果，将该状态加入待清空队列
	lfx.push_back(Quad(j1,j2,i1,w));
	// 二分求i2的位置
	int l, r, k;
	l = i1-1;
	r = n+1;
	while (r-l > 1)
	{
		k = l+r>>1;
		if (sumx[j1][j2][k]-sumx[j1][j2][i1-1] <= w) l = k; else r = k;
	}
	if (sumx[j1][j2][l]-sumx[j1][j2][i1-1] != w) l = -1;
    return fx[j1][j2][i1][w]=l;
}

/*
求：以i1为上边界、i2为下边界、j1为左边界的矩形中，右边界为多少的矩形
重量和是w。如果不存在则返回-1
和上面对称
*/
int calcy(int i1, int i2, int j1, int w)
{
	if (fy[i1][i2][j1][w] != 0) return fy[i1][i2][j1][w];
	lfy.push_back(Quad(i1,i2,j1,w));
	int l, r, k;
	l = j1-1;
	r = m+1;
	while (r-l > 1)
	{
		k = l+r>>1;
		if (sumy[i1][i2][k]-sumy[i1][i2][j1-1] <= w) l = k; else r = k;
	}
	if (sumy[i1][i2][l]-sumy[i1][i2][j1-1] != w) l = -1;
    return fy[i1][i2][j1][w]=l;
}

/*
求(i1,j1)~(i2,j2)的矩形能否切出sta中的巧克力
*/
bool work(int i1, int i2, int j1, int j2, int sta)
{
	//记忆化：求过了则直接返回
	if (f[i1][i2][j1][sta] != 0) return f[i1][i2][j1][sta]==1;
	if (bg[sta] == ed[sta]) return true;
	//未求过，将该状态加入待清空队列
	lf.push_back(Quad(i1,i2,j1,sta));
	int i, sta2, x, y;
	//枚举sta的每个非空真子集
	for (i=bg[sta]; i<ed[sta]; ++i)
	{
		sta2 = c[i];
		
		//尝试横向切
		x = calcx(j1,j2,i1,suma[sta2]);
		if (x != -1)
		if (work(i1,x,j1,j2,sta2) && work(x+1,i2,j1,j2,sta-sta2))
		{
			f[i1][i2][j1][sta] = 1;
			return true;
		}
		
		//尝试纵向切
		y = calcy(i1,i2,j1,suma[sta2]);
		if (y != -1)
		if (work(i1,i2,j1,y,sta2) && work(i1,i2,y+1,j2,sta-sta2))
		{
			f[i1][i2][j1][sta] = 1;
			return true;
		}
	}
	f[i1][i2][j1][sta] = -1;
	return false;
}

void dfs(int sta, int t)
{
	if (t == MAXK)
	{
		if (sta > 0) c[nc++] = sta;
		return;
	}
	if (sta&e[t]) dfs(sta-e[t], t+1);
	dfs(sta, t+1);
}

int main()
{
	freopen("chocolate.in", "r", stdin);
	freopen("chocolate.out", "w", stdout);
	e[0] = 1; 
	for (i=1; i<=MAXK; ++i) e[i] = e[i-1]*2;
	
	//预处理每个sta有哪些非空真子集，连续存储在队列c中
	nc = 1;
	for (sta=1; sta<e[MAXK]; ++sta)
	{
		bg[sta] = nc; //bg表示sta的子集在c中的开头位置
		dfs(sta, 0); //dfs求sta的非空真子集
		--nc;
		ed[sta] = nc; //ed表示sta的子集在c中的结尾位置
	}
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &K);
		for (i=1; i<=n; ++i)
		for (j=1; j<=m; ++j)
		{
			scanf("%d", &w);
			//sumy[i][j][k]:从第i行到第j行，从第1列到第k列构成的矩形的重量和
			sumy[i][i][j] = sumy[i][i][j-1]+w;
			//sumx[i][j][k]:从第i列到第j列，从第1行到第k行构成的矩形的重量和
			sumx[j][j][i] = sumx[j][j][i-1]+w;
		}
		for (l=1; l<n; ++l)
		for (r=l+1; r<=n; ++r)
		for (j=1; j<=m; ++j) sumy[l][r][j] = sumy[l][r-1][j]+sumy[r][r][j];
		for (l=1; l<m; ++l)
		for (r=l+1; r<=m; ++r)
		for (i=1; i<=n; ++i) sumx[l][r][i] = sumx[l][r-1][i]+sumx[r][r][i];
		
		for (i=1; i<=K; ++i) scanf("%d", &a[i]);
		//求出{ai}的各个子集的重量和
		//suma[sta]：sta中的巧克力的总重量
		for (sta=0; sta<e[K]; ++sta)
		{
			suma[sta] = 0;
			for (i=sta, j=1; i>0; i>>=1, ++j)
			if (i&1) suma[sta] += a[j];
		}
		
		// 如果所有ai的总重量!=巧克力的总重量
		if (suma[e[K]-1] != sumy[1][n][m])
		{
			printf("no\n");
			continue;
		}
		
		//lf、lfx、lfy用于记录哪些状态被记忆化了，用于之后清零
		lf.clear();
		lfx.clear();
		lfy.clear();
		
		if (work(1,n,1,m,e[K]-1)) printf("yes\n");
		else printf("no\n");
		
		//清零记忆化过的状态
		for (std::list<Quad>::iterator it=lf.begin(); it!=lf.end(); ++it) f[it->a][it->b][it->c][it->d] = 0;
		for (std::list<Quad>::iterator it=lfx.begin(); it!=lfx.end(); ++it) fx[it->a][it->b][it->c][it->d] = 0;
		for (std::list<Quad>::iterator it=lfy.begin(); it!=lfy.end(); ++it) fy[it->a][it->b][it->c][it->d] = 0;
	}
	return 0;
}
