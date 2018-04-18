#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 2000000000
#define MIN(a,b) (a<b?a:b)

int n,a[305],f[305],odd[305],even[305];

int main()
{
    freopen("2462.in","r",stdin);
    freopen("2462.out","w",stdout);

    scanf("%d",&n);

    bool AllOne=true;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if (a[i]!=1) AllOne=false;
    }

    if (n==2) printf("%d\n",MIN(a[1],a[2])); else
        if (n==3) printf("%d\n",MIN(a[1]+a[3],a[2])); else
            if (AllOne) printf("%d\n",n/2); else
                {
                    int odds=n/2+n%2,evens=n/2;
                    for (int i=1;i<=n;i++)
                        if (i%2) odd[i/2+1]=a[i]; else even[i/2]=a[i];
                    sort(odd+1,odd+1+odds);
                    sort(even+1,even+1+evens);
                    int ans=0;
                    for (int i=1;i<=odds/2;i++) ans+=odd[i];
                    for (int i=1;i<=evens/2;i++) ans+=even[i];
                    if (odds%2 && !evens%2) ans+=odd[odds/2+1]; else
                        if (!odds%2 && evens%2) ans+=even[evens/2+1]; else
                            ans+=MIN(odd[odds/2+1],even[evens/2+1]);
                    printf("%d\n",ans);
                }

    return 0;
}
