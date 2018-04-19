#include <cstdio>

struct SegTree
{
	int add,cnt[10];
} tree[1000005];
int n,m;
char NUM[250005];

void BuildTree(int cur,int l,int r)
{
	if (l==r)
	{
		int num=NUM[l-1]-48;
		tree[cur].cnt[num]++;
		return;
	}
	BuildTree(cur*2,l,(l+r)/2);
	BuildTree(cur*2+1,(l+r)/2+1,r);
	for (int i=0;i<10;i++)
		tree[cur].cnt[i]=tree[cur*2].cnt[i]+tree[cur*2+1].cnt[i];
	return;
}

void Down(int cur,int l,int r)
{
	int Left=cur*2,Right=cur*2+1;

	tree[cur].add%=10;

	for (int i=1;i<=tree[cur].add;i++)
	{
		int cnt9_left=tree[Left].cnt[9],
			cnt9_right=tree[Right].cnt[9];
		for (int i=9;i>=1;i--)
			tree[Left].cnt[i]=tree[Left].cnt[i-1],
            tree[Right].cnt[i]=tree[Right].cnt[i-1];
		tree[Left].cnt[0]=cnt9_left;
		tree[Right].cnt[0]=cnt9_right;
	}

    tree[Left].add+=tree[cur].add;
	tree[Right].add+=tree[cur].add;
	tree[cur].add=0;
	return;
}

void Change(int cur,int l,int r,int s,int t)
{
	if (t<l||s>r) return;
	if (s<=l&&r<=t)
	{
		tree[cur].add++;
		int cnt9=tree[cur].cnt[9];
		for (int i=9;i>=1;i--) tree[cur].cnt[i]=tree[cur].cnt[i-1];
		tree[cur].cnt[0]=cnt9;
		return;
	}
	Down(cur,l,r);
	Change(cur*2,l,(l+r)/2,s,t);
	Change(cur*2+1,(l+r)/2+1,r,s,t);
	for (int i=0;i<10;i++)
		tree[cur].cnt[i]=tree[cur*2].cnt[i]+tree[cur*2+1].cnt[i];
	return;
}

int Sum(int cur)
{
	return  tree[cur].cnt[1]+
			tree[cur].cnt[2]*2+
			tree[cur].cnt[3]*3+
			tree[cur].cnt[4]*4+
			tree[cur].cnt[5]*5+
			tree[cur].cnt[6]*6+
			tree[cur].cnt[7]*7+
			tree[cur].cnt[8]*8+
			tree[cur].cnt[9]*9;
}

int Query(int cur,int l,int r,int s,int t)
{
	if (t<l||s>r) return 0;
	if (s<=l&&r<=t) return Sum(cur);
	Down(cur,l,r);
	return Query(cur*2,l,(l+r)/2,s,t)+
           Query(cur*2+1,(l+r)/2+1,r,s,t);
}

int main()
{
	freopen("1665.in","r",stdin);
	freopen("1665.out","w",stdout);

	scanf("%d%d\n%s",&n,&m,NUM);
	BuildTree(1,1,n);
	for (int i=1,a,b;i<=m;i++)
	{
		scanf("%d%d",&a,&b);
		printf("%d\n",Query(1,1,n,a,b));
		Change(1,1,n,a,b);
	}

	return 0;
}
