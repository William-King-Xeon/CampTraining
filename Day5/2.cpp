#include <cstdio>
#include <iostream>
#include <algorithm>

typedef unsigned long long ULL;

using namespace std;

int n,m,ans,a[100005],tmp[100005];
string S,t,ps,qs;
bool sign[100005];
ULL Hash[100005],POW[100005];

ULL GetHashValue(int x,int l)
{
    int y=x+l-1;
    return Hash[y]-Hash[x-1]*POW[l];
}

bool BelowOrEqual(int x,int y)
{
    int l=0,r=m+1;

    while (l+1<r)
    {
        int mid=(l+r)/2;
        if (GetHashValue(x,mid)!=GetHashValue(y,mid)) r=mid;
            else l=mid;
    }

    if (x+l>=n) return true;
        else if (y+l>=n) return false;
    return S[x+l]<=S[y+l];
}

void Merge_Sort(int l,int r)
{
    if (l>=r) return;

    int mid=(l+r)/2;
    Merge_Sort(l,mid);
    Merge_Sort(mid+1,r);

    int p=l,q=mid+1,k=l;
    while (p<=mid && q<=r)
        if (BelowOrEqual(a[p],a[q])) tmp[k++]=a[p++];
            else
            {
                tmp[k++]=a[q++];
                ans+=mid-p+1;
            }

    while (p<=mid) tmp[k++]=a[p++];
    while (q<=r)   tmp[k++]=a[q++];

    for (int temp=l;temp<=r;temp++) a[temp]=tmp[temp];
    return;
}

int main()
{
    freopen("2464.in","r",stdin);
    freopen("2464.out","w",stdout);

    scanf("%d%d",&n,&m);
    cin >> S;

    for (int i=0;i<S.size();i++) Hash[i]=Hash[i-1]*31+(S[i]-'a'+1);
    POW[0]=1;
    for (int i=1;i<=m;i++) POW[i]=POW[i-1]*31;

    for (int i=0;i<n;i++) a[i]=i;
    Merge_Sort(0,n-1);

    printf("%d\n",ans);
    return 0;
}
