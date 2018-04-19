#include <cstdio>
#define MAX(a,b) (a>b?a:b)

struct SegTree
{
    int num,down;
} tree[400005];

int n,m,a[100005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur].num=a[l];
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur].num=MAX(tree[cur*2].num,tree[cur*2+1].num);
    return;
}

void Down(int cur)
{
    tree[cur*2].down+=tree[cur].down;
    tree[cur*2].num+=tree[cur].down;
    tree[cur*2+1].down+=tree[cur].down;
    tree[cur*2+1].num+=tree[cur].down;
    tree[cur].down=0;
    return;
}

void Change(int cur,int l,int r,int s,int t,int x)
{
    if (r<s||l>t) return;
    if (s<=l&&r<=t)
    {
        tree[cur].num+=x;
        tree[cur].down+=x;
        return;
    }
    Down(cur);
    Change(cur*2,l,(l+r)/2,s,t,x);
    Change(cur*2+1,(l+r)/2+1,r,s,t,x);
    tree[cur].num=MAX(tree[cur*2].num,tree[cur*2+1].num);
    return;
}

int Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return -2147483648;
    if (s<=l&&r<=t) return tree[cur].num;
    Down(cur);
    int Left=Query(cur*2,l,(l+r)/2,s,t),
        Right=Query(cur*2+1,(l+r)/2+1,r,s,t);
    return MAX(Left,Right);
}

int main()
{
    freopen("1663.in","r",stdin);
    freopen("1663.out","w",stdout);

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
            printf("%d",Query(1,1,n,l,r));
        }
    }

    return 0;
}
