#include <cstdio>

struct SegTree
{
    long long sum,down;
} tree[400005];

int n,m,a[100005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur].sum=a[l];
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur].sum=tree[cur*2].sum+tree[cur*2+1].sum;
    return;
}

void Down(int cur,int l,int r)
{
    int mid=(l+r)/2;
    tree[cur*2].down+=tree[cur].down;
    tree[cur*2].sum+=tree[cur].down*(mid-l+1);
    tree[cur*2+1].down+=tree[cur].down;
    tree[cur*2+1].sum+=tree[cur].down*(r-mid);
    tree[cur].down=0;
    return;
}

void Change(int cur,int l,int r,int s,int t,int x)
{
    if (r<s||l>t) return;
    if (s<=l&&r<=t)
    {
        tree[cur].sum+=(r-l+1)*x;
        tree[cur].down+=x;
        return;
    }
    Down(cur,l,r);
    Change(cur*2,l,(l+r)/2,s,t,x);
    Change(cur*2+1,(l+r)/2+1,r,s,t,x);
    tree[cur].sum=tree[cur*2].sum+tree[cur*2+1].sum;
    return;
}

long long Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return 0;
    if (s<=l&&r<=t) return tree[cur].sum;
    Down(cur,l,r);
    return Query(cur*2,l,(l+r)/2,s,t)+Query(cur*2+1,(l+r)/2+1,r,s,t);
}

int main()
{
    freopen("1664.in","r",stdin);
    freopen("1664.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<=n;i++) scanf("%d",&a[i]);

    BuildTree(1,1,n);

    scanf("%d",&m);

    for (int i=1,cmd,l,r,c;i<=m;i++)
    {
        scanf("%d",&cmd);
        if (cmd==1)
        {
            scanf("%d%d%d",&l,&r,&c);
            Change(1,1,n,l,r,c);
        } else
        {
            scanf("%d%d",&l,&r);
            printf("%lld",Query(1,1,n,l,r));
        }
    }

    return 0;
}
