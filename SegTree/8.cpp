#include <cstdio>
#include <algorithm>

using namespace std;

#define MIN(a,b) (a<b?a:b)

struct COW
{
    int h,id;
} cow[100005];

int n,marks,mark[100005],tree[400005];

bool Compare(COW a,COW b)
{
    return a.h>b.h;
}

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur]=n+1;
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur]=MIN(tree[cur*2],tree[cur*2+1]);
    return;
}

void Change(int cur,int l,int r,int x,int y)
{
    if (r<x||l>x) return;
    if (l==x&&r==x)
    {
        tree[cur]=y;
        return;
    }
    Change(cur*2,l,(l+r)/2,x,y);
    Change(cur*2+1,(l+r)/2+1,r,x,y);
    tree[cur]=MIN(tree[cur*2],tree[cur*2+1]);
    return;
}

int Query(int cur,int l,int r,int s,int t)
{
    if (r<s||l>t) return n+1;
    if (s<=l&&r<=t) return tree[cur];
    int Left=Query(cur*2,l,(l+r)/2,s,t),
        Right=Query(cur*2+1,(l+r)/2+1,r,s,t);
    return MIN(Left,Right);
}

int main()
{
    freopen("1667.in","r",stdin);
    freopen("1667.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&cow[i].h);
        cow[i].id=i;
    }

    sort(cow+1,cow+1+n,Compare);

    for (int i=1;i<=n;i++)
    {
        if (cow[i].h!=cow[i-1].h) marks++;
        mark[cow[i].id]=marks;
    }

    BuildTree(1,1,marks);

    long long ans=0;
    for (int i=n;i>=1;i--)
    {
        ans+=Query(1,1,marks,1,mark[i])-i-1;
        Change(1,1,marks,mark[i],i);
    }

    printf("%lld",ans);

    return 0;
}
