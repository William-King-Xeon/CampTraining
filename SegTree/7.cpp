#include <cstdio>
#define MIN(a,b) (a<b?a:b)

struct SegTree
{
    int num,down;
} tree[400005];

int c,s,r;

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur].num=s;
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur].num=MIN(tree[cur*2].num,tree[cur*2+1].num);
    return;
}

void Down(int cur)
{
    tree[cur*2].down+=tree[cur].down;
    tree[cur*2].num-=tree[cur].down;
    tree[cur*2+1].down+=tree[cur].down;
    tree[cur*2+1].num-=tree[cur].down;
    tree[cur].down=0;
    return;
}

void Change(int cur,int l,int r,int s,int t,int x)
{
    if (r<s||l>t) return;
    if (s<=l&&r<=t)
    {
        tree[cur].num-=x;
        tree[cur].down+=x;
        return;
    }
    Down(cur);
    Change(cur*2,l,(l+r)/2,s,t,x);
    Change(cur*2+1,(l+r)/2+1,r,s,t,x);
    tree[cur].num=MIN(tree[cur*2].num,tree[cur*2+1].num);
    return;
}

int Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return 2000000000;
    if (s<=l&&r<=t) return tree[cur].num;
    Down(cur);
    int Left=Query(cur*2,l,(l+r)/2,s,t),
        Right=Query(cur*2+1,(l+r)/2+1,r,s,t);
    return MIN(Left,Right);
}

int main()
{
    freopen("1666.in","r",stdin);
    freopen("1666.out","w",stdout);

    scanf("%d%d%d",&c,&s,&r);

    BuildTree(1,1,c);

    for (int i=1,o,d,n;i<=r;i++)
    {
        scanf("%d%d%d",&o,&d,&n);
        d--;
        if (Query(1,1,c,o,d)>=n)
        {
            printf("YES\n");
            Change(1,1,c,o,d,n);
        } else
            printf("NO\n");
    }

    return 0;
}
