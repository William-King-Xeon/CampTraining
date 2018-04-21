#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long LL;

LL n,k,m,a[1000005],avg,p[1000005];
bool visit[1000005];

int main()
{
    freopen("2488.in","r",stdin);
    freopen("2488.out","w",stdout);

    scanf("%lld%lld",&n,&k);

    for (int i=0;i<n;i++)
    {
        scanf("%lld",&a[i]);
        avg+=a[i];
    }

    if (avg%n) { printf("gg\n");return 0; }
    avg/=n;

    bool OK=true;
    for (int i=0;i<n;i++)
        if (a[i]!=avg) { OK=false;break; }

    if (OK) { printf("0\n");return 0; }
    if (k==n) { printf("gg\n");return 0; }

    LL ans=0,sum,last;

    for (int i=0,tmp=0;i<n;i++,tmp=i)
        if (!visit[i])
        {
            sum=last=m=0;
            while (!visit[tmp])
            {
                visit[tmp]=true,sum+=a[tmp];
                p[m]=a[tmp]+last-avg;
                last=p[m];
                m++,tmp=(tmp+k+1)%n;
            }
            if (sum%m || sum/m!=avg) { printf("gg\n");return 0; }

            sort(p,p+m);
            for (int j=0;j<m;j++) ans+=abs(p[j]-p[m/2]);
        }

    printf("%lld\n",ans);

    return 0;
}
