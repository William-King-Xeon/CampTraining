#include <cstdio>

int T,n,m,num;

int main()
{
    while (T--)
    {
        num = 1;
        while (~scanf("%d%d",&n,&m) && (n!= 0||m!=0))
        {
            int cnt=0;
            for (int a=1;a<n;++a)
                for (int b=a+1;b<n;++b)
                {
                    if ((a * a + b * b + m) % (a * b) == 0)
                        cnt++;
                }
            printf("Case %d: %d\n",num,cnt);
            num++;
        }
        if (T==1) printf("\n");
    }
    return 0;
}
