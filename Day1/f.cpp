#include <cstdio>

int n,a;

int main()
{
    scanf("%d",&n);
    while (n!=0)
    {
        int cur=0,ans=0;
        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if (a>cur) ans+=6*(a-cur)+5;
                else ans+=4*(cur-a)+5;
            cur=a;
        }
        printf("%d\n",ans);
        scanf("%d",&n);
    }
    return 0;
}
