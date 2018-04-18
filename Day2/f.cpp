#include <cstdio>
#include <cstring>

#define MOD 10007
#define clean(x) (memset(x,0,sizeof(x)))
#define copy(x,y) (memcpy(x,y,sizeof(y)))

int T,n;

void mul(int a[3][3],int b[3][3])
{
    int c[3][3];
    clean(c);
    for (int i=0;i<3;i++)
        for (int j=0;j<3;j++)
            for (int k=0;k<3;k++)
                c[i][j]=(c[i][j]+a[i][k]*b[k][j]%MOD)%MOD;
    copy(a,c);
    return;
}

int main()
{
    scanf("%d",&T);

    while (T--)
    {
        scanf("%d",&n);
        int matrix[3][3]=
            {
                {2,1,0},
                {2,2,2},
                {0,1,2}
            },
            f[3][3]=
            {
                {1,0,0},
                {0,1,0},
                {0,0,1}
            };
        while (n)
        {
            if (n&1) mul(f,matrix);
            mul(matrix,matrix);
            n>>=1;
        }

        printf("%d\n",f[0][0]);
    }

    return 0;
}
