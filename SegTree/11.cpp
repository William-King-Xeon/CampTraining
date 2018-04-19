#include <cstdio>
#define INF 214748364800005LL
#define MIN(a,b) (a<b?a:b)

int n,p,q,w[100005];
long long sum[100005],tree[400005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur]=sum[l];
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur]=MIN(tree[cur*2],tree[cur*2+1]);
    return;
}

long long Query(int cur,int l,int r,int s,int t)
{
	if (t<l||s>r) return INF;
	if (s<=l&&r<=t) return tree[cur];
    long long Left=Query(cur*2,l,(l+r)/2,s,t),
              Right=Query(cur*2+1,(l+r)/2+1,r,s,t);
	return MIN(Left,Right);
}

int main()
{
    freopen("1762.in","r",stdin);
    freopen("1762.out","w",stdout);

    scanf("%d%d%d",&n,&p,&q);

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&w[i]);
        sum[i]=sum[i-1]+w[i];
    }

    BuildTree(1,0,n);
    long long ans=-INF;
    for (int i=p;i<=n;i++)
    {
        int start=i-q,end=i-p;
        if (start<0) start=0;
        if (end<0) end=0;
        if (sum[i]-Query(1,0,n,start,end)>ans)
            ans=sum[i]-Query(1,0,n,start,end);
    }

    printf("%lld\n",ans);
}
