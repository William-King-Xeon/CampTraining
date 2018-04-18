#include <cstdio>
#include <map>

using namespace std;

map <int,int> cnt,same;

int n,m,a[300005],b[300005],num[300005],ans=300005;

int main()
{
    freopen("2463.in","r",stdin);
    freopen("2463.out","w",stdout);
    
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        if (cnt[a[i]]==0) num[++m]=a[i];
        cnt[a[i]]++;
        if (cnt[b[i]]==0) num[++m]=b[i];
        cnt[b[i]]++;
        if (a[i]==b[i]) cnt[a[i]]--;
    }

    for (int i=1;i<=m;i++)
        if (cnt[num[i]]>=(double)n/2)
        {
            int curans=0,tmp=0;
            for (int j=1;j<=n;j++)
                if (a[j]==num[i]) tmp++;
            if (tmp<(double)n/2)
                for (int j=1;j<=n && tmp<(double)n/2;j++)
                    if (b[j]==num[i] && a[j]!=b[j])
                        tmp++,curans++;
            if (curans<ans) ans=curans;
        }

    if (ans==300005) printf("Impossible\n");
        else printf("%d\n",ans);

    return 0;
}
