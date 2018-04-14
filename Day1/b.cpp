#include <cstdio>
#include <cstring>

int T;
char sa[10005],sb[10005];

struct BIGNUM
{
    int num[10005];
    int len;
} a,b,c;

BIGNUM ADD(BIGNUM a,BIGNUM b)
{
    BIGNUM c;
    for (int i=0;i<10005;i++) c.num[i]=0;

    if (a.len>b.len) c.len=a.len; else c.len=b.len;

    for (int i=0;i<c.len;i++)
    {
        c.num[i]+=a.num[i]+b.num[i];
        c.num[i+1]+=c.num[i]/10;
        c.num[i]%=10;
    }

    if (c.num[c.len]!=0) c.len++;
    return c;
}

int PRINT(BIGNUM x)
{
    for (int i=x.len-1;i>=0;i--)
        printf("%d",x.num[i]);
    return 0;
}

int main()
{
    //freopen("b.out","w",stdout);

    scanf("%d",&T);

    for (int t=1;t<=T;t++)
    {
        scanf("%s%s",sa,sb);

        for (int i=0;i<10005;i++) a.num[i]=0;
        for (int i=0;i<10005;i++) b.num[i]=0;
        a.len=strlen(sa);
        b.len=strlen(sb);
        for (int i=0;i<a.len;i++) a.num[a.len-i-1]=sa[i]-'0';
        for (int i=0;i<b.len;i++) b.num[b.len-i-1]=sb[i]-'0';

        c=ADD(a,b);

        printf("Case %d:\n",t);
        PRINT(a);
        printf(" + ");
        PRINT(b);
        printf(" = ");
        PRINT(c);
        if (t!=T) printf("\n\n"); else printf("\n");
    }

    return 0;
}
