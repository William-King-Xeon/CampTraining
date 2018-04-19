#include <cstdio>

long long tree[400005];

int n,a[100005];

void BuildTree(int cur,int l,int r)
{
    if (l==r)
    {
        tree[cur]=a[l];
        printf("%lld ",tree[cur]);
        return;
    }
    BuildTree(cur*2,l,(l+r)/2);
    BuildTree(cur*2+1,(l+r)/2+1,r);
    tree[cur]=tree[cur*2]+tree[cur*2+1];
    printf("%lld ",tree[cur]);
    return;
}

int main()
{
    freopen("1660.in","r",stdin);
    freopen("1660.out","w",stdout);
    
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]);

    BuildTree(1,1,n);

    printf("\n");

    return 0;
}
