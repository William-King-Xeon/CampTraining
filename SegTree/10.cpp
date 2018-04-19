#include <cstdio>
#define INF 100000000
#define MAX(a,b) (a>b?a:b)

int n,d,m,a[2005],b[2005],f[2005][2005];

int tree[2005][8005];

int c,s,r;

void BuildTree(int T,int cur,int l,int r)
{
    if (l==r)
    {
        tree[T][cur]=-INF;
        return;
    }
    BuildTree(T,cur*2,l,(l+r)/2);
    BuildTree(T,cur*2+1,(l+r)/2+1,r);
    tree[T][cur]=MAX(tree[T][cur*2],tree[T][cur*2+1]);
    return;
}

void Change(int T,int cur,int l,int r,int x,int y)
{
    if (r<x||l>x) return;
    if (l==x&&r==x)
    {
        tree[T][cur]=y;
        return;
    }
    Change(T,cur*2,l,(l+r)/2,x,y);
    Change(T,cur*2+1,(l+r)/2+1,r,x,y);
    tree[T][cur]=MAX(tree[T][cur*2],tree[T][cur*2+1]);
    return;
}

int main()
{
    freopen("1725.in","r",stdin);
    freopen("1725.out","w",stdout);

    scanf("%d%d%d",&n,&d,&m);

    for (int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);

    for (int i=0;i<=m;i++) BuildTree(i,1,1,n);
    Change(0,1,1,n,1,a[1]);

    int ans=0,start=1;
    for (int i=2;i<=n;i++)
    {
        while (b[i]-b[start]>d)
        {
            for (int j=0;j<=m;j++) Change(j,1,1,n,start,-INF);
            start++;
        }

        for (int j=m;j>=1;j--)
        {
            if (tree[j-1][1]+a[i]>ans) ans=tree[j-1][1]+a[i];
            Change(j,1,1,n,i,tree[j-1][1]+a[i]);
        }
    }

    printf("%d\n",ans);

    return 0;
}
