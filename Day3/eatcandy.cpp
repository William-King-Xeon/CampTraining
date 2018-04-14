#include <cstdio>
#include <queue>

using namespace std;

queue<int> q;

int n,m,a[100005],candy[100005];
bool In[100005];

int main()
{
    freopen("2460.in","r",stdin);
    freopen("2460.out","w",stdout);

    scanf("%d%d",&n,&m);

    for (int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        candy[a[i]]++;
    }

    int len=0,maxlen=0,ans=0;
    for (int i=1;i<=n;i++)
    {
        if (!In[a[i]]) In[a[i]]=true,q.push(a[i]),ans++,len++;
        candy[a[i]]--;
        while (candy[q.front()]==0 && !q.empty()) In[q.front()]=false,q.pop(),len--;
        if (len>maxlen) maxlen=len;
    }

    printf("%d %d\n",ans,maxlen);

    return 0;
}
