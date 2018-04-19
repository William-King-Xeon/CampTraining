#include <cstdio>

long long tree[400005];

int n,q,a[100005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur]=a[l];
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur]=tree[cur*2]+tree[cur*2+1];
    return;
}

long long Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return 0;
    if (s<=l&&r<=t) return tree[cur];
    return Query(cur*2,l,(l+r)/2,s,t)+
           Query(cur*2+1,(l+r)/2+1,r,s,t);
}

int main()
{
    freopen("1661.in","r",stdin);
    freopen("1661.out","w",stdout);

    scanf("%d%d",&n,&q);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    BuildTree(1,1,n);

    for (int i=1,s,t;i<=q;i++)
    {
        scanf("%d%d",&s,&t);
        if (s>t) { int b=s;s=t;t=b; }
        printf("%lld",Query(1,1,n,s,t));
    }

    return 0;
}
