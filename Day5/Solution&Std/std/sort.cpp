#include <cstdio>

#define mo 1000000007
#define N 50055

int f[N],s[N],tmp[N],n,m,i,ch,ans;
long long hash[N],pow[N];

//二分+哈希求以i开头的和以j开头的两个子串哪个字典序更小
bool lessThanOrEqual(int i, int j)
{
	if (i == j) return true;
	int l, r, k;
	long long hsi, hsj;
	//二分求i和j开始从左向右第一位不同的位
	l = 0;
	r = m+1;
	if (n-j+2 < r) r = n-j+2;
	if (n-i+2 < r) r = n-i+2;
	while (r-l > 1)
	{
		k = (l+r)/2;
		//子串[i,i+k-1]的哈希值
		hsi = hash[i+k-1]-hash[i-1]*pow[k]%mo;
		if (hsi < 0) hsi += mo;
		//子串[j,j+k-1]的哈希值
		hsj = hash[j+k-1]-hash[j-1]*pow[k]%mo;
		if (hsj < 0) hsj += mo;
		if (hsi == hsj) l = k; else r = k;
	}
	//s[i+l]和s[j+l]是第一位不同的位
	if (l == m) return true;
	return s[i+l] < s[j+l];
}

//归并排序
void sort(int l, int r)
{
	if (l == r) return;
	int mi = (l+r)/2;
	sort(l, mi);
	sort(mi+1, r);
	int i=l, j=mi+1;
	int nt = l;
	while (i<=mi || j<=r)
	{
		bool ilej;
		if (i > mi) ilej = false;
		else
		if (j > r) ilej = true;
		else ilej = lessThanOrEqual(f[i],f[j]);
		if (ilej) tmp[nt++] = f[i++];
		else
		{
			tmp[nt++] = f[j++];
			//从右区间取数时，右区间和左区间之间产生了继续对
			//累加答案
			ans += mi-i+1;
		}
	}
	for (i=l; i<=r; ++i) f[i] = tmp[i];
}

int main()
{
	freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	scanf("%d%d", &n, &m);
	hash[0] = 0;
	pow[0] = 1;
	for (i=1; i<=n; ++i)
	{
		for (ch=getchar(); ch<=32; ch=getchar());
		s[i] = ch-96;
		//预处理hash[i]=子串[1,i]的哈希值
		hash[i] = (hash[i-1]*29+s[i])%mo;
		//预处理pow[i]=29^i
		pow[i] = pow[i-1]*29%mo;
		f[i] = i;
	}
	s[n+1] = 0;
	sort(1, n);
	printf("%d\n", ans);
	return 0;
}
