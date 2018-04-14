#include <cstdio>
#include <cstring>
#define MOD 10000

int n;

void mul(int a[2],int b[2][2])
{
    int c[2];
    memset(c,0,sizeof(c));
    for (int j=0;j<2;j++)
        for (int k=0;k<2;k++)
            c[j]=(c[j]+a[k]*b[k][j]%MOD)%MOD;
    memcpy(a,c,sizeof(c));
    return;
}

void mulself(int a[2][2])
{
    int b[2][2];
    memset(b,0,sizeof(b));
    for (int i=0;i<2;i++)
        for (int j=0;j<2;j++)
            for (int k=0;k<2;k++)
                b[i][j]=(b[i][j]+a[i][k]*a[k][j]%MOD)%MOD;
    memcpy(a,b,sizeof(b));
    return;
}

int main()
{
    scanf("%d",&n);

    while (n!=-1)
    {
        int f[2]={0,1},m[2][2]={{0,1},{1,1}};

        while (n)
        {
            if (n%2) mul(f,m);
            mulself(m);
            n/=2;
        }

        printf("%d\n",f[0]);
        scanf("%d",&n);
    }

    return 0;
}
