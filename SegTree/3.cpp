#include <cstdio>
#define MAX(a,b) (a>b?a:b)

int tree[400005];

int n,m,a[100005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur]=a[l];
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur]=MAX(tree[cur*2],tree[cur*2+1]);
    return;
}

void Change(int cur,int l,int r,int s,int t)
{
    if (r<s||l>s) return;
    if (l==s&&r==s)
    {
        tree[cur]=t;
        return;
    }
    Change(cur*2,l,(l+r)/2,s,t);
    Change(cur*2+1,(l+r)/2+1,r,s,t);
    tree[cur]=MAX(tree[cur*2],tree[cur*2+1]);
    return;
}

int Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return -2147483648;
    if (s<=l&&r<=t) return tree[cur];
    int Left=Query(cur*2,l,(l+r)/2,s,t),
        Right=Query(cur*2+1,(l+r)/2+1,r,s,t);
    return MAX(Left,Right);
}

int main()
{
    freopen("1662.in","r",stdin);
    freopen("1662.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    BuildTree(1,1,n);

    scanf("%d",&m);

    for (int i=1,cmd,x,y;i<=m;i++)
    {
        scanf("%d%d%d",&cmd,&x,&y);
        if (cmd==1) Change(1,1,n,x,y);
            else printf("%d\n",Query(1,1,n,x,y));
    }

    return 0;
}
