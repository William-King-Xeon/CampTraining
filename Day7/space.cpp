#include <cstdio>
#include <map>
using namespace std;

#define SQR(x) ((x)*(x))

int n,x[1005],y[1005],ans;
map<int,int> Cnt[1005];

int main()
{
    freopen("2487.in","r",stdin);
    freopen("2487.out","w",stdout);

    scanf("%d",&n);

    for (int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);

    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
            if (i!=j)
                Cnt[i][SQR(x[i]-x[j])+SQR(y[i]-y[j])]++;

    for (int i=1;i<=n;i++)
        for (map<int,int>::iterator cur=Cnt[i].begin();cur!=Cnt[i].end();cur++)
            ans+=cur->second*(cur->second-1);

    if (ans==0) printf("WA\n");
        else printf("%d\n",ans/2);

    return 0;
}
