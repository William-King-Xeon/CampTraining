#include <cstdio>

int T,n,a;

int GCD(int x,int y)
{
    int r=x%y;
    while (r!=0)
    {
        x=y;y=r;
        r=x%y;
    }
    return y;
}

int main()
{
    scanf("%d",&T);

    for (int t=1;t<=T;t++)
    {
        scanf("%d",&n);

        int gcd;
        long long mul=1;

        for (int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            if (i==1) gcd=a,mul=a;
                else mul=mul*a/GCD(mul,a);
        }

        printf("%d\n",mul);
    }

    return 0;
}
