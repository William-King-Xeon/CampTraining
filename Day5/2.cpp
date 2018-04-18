#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

long long n,N,m,ans,a[100005],tmp[100005];
string S,t,str[100005],ps,qs;
bool sign[100005];

void Merge_Sort(long long l,long long r)
{
    if (l>=r) return;

    long long mid=(l+r)/2;
    Merge_Sort(l,mid);
    Merge_Sort(mid+1,r);

    long long p=l,q=mid+1,k=l;
    while (p<=mid && q<=r)
    {
        if (sign[a[p]]) ps=str[a[p]]; else ps=S.substr(a[p],m);
        if (sign[a[q]]) qs=str[a[q]]; else qs=S.substr(a[q],m);
        if (ps<=qs) tmp[k++]=a[p++];
            else
            {
                tmp[k++]=a[q++];
                ans+=mid-p+1;
            }
    }

    while (p<=mid) tmp[k++]=a[p++];
    while (q<=r)   tmp[k++]=a[q++];

    for (int temp=l;temp<=r;temp++) a[temp]=tmp[temp];
    return;
}

int main()
{
    //freopen("2464.in","r",stdin);
    //freopen("2464.out","w",stdout);

    srand(time(NULL));

    scanf("%lld%lld",&n,&m);
    cin >> S;

    for (int i=0;i<n;i++)
        if (!rand()%5) str[i]=S.substr(i,m),sign[i]=true;

    for (int i=0;i<n;i++) a[i]=i;
    Merge_Sort(0,n-1);

    printf("%lld\n",ans);

    return 0;
}
