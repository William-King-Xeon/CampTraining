#include <cstdio>
#include <algorithm>

using namespace std;

int n,a[1000005];

int main()
{
    while (~scanf("%d",&n))
    {
        for (int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int cnt=1;

        for (int i=2;i<=n+1;i++)
            if (a[i]==a[i-1]) cnt++;
                else
                {
                    if (cnt>=(n+1)/2) printf("%d\n",a[i-1]);
                    cnt=1;
                }
    }

    return 0;
}
