#include <cstdio>
#pragma GCC optimize(2)
typedef unsigned long long ULL;

char str[1000005];
int T,len;
ULL _hash[1000005],_p[1000005];

ULL GetHash(int x,int y)
{
    if (x==0) return _hash[y];
        else return _hash[y]-_hash[x-1]*_p[y-x+1];
}

int main()
{
    freopen("2492.in","r",stdin);
    freopen("2492.out","w",stdout);

    _p[0]=1;
    for (int i=1;i<=1000000;i++) _p[i]=_p[i-1]*37;

    scanf("%d",&T);

    while (T--)
    {
        scanf("%d%s",&len,str);

        _hash[0]=str[0]-'a'+1;
        for (int i=1;i<len;i++) _hash[i]=_hash[i-1]*37+str[i]-'a'+1;

        int ans=0;
        for (int plen=1;plen<=len/2;plen++)
            if (GetHash(0,plen-1)==GetHash(len-plen,len-1))
                for (int slen=1;slen<=len/2-plen;slen++)
                    if (GetHash(plen,plen+slen-1)==GetHash(len-plen-slen,len-plen-1))
                        ans= plen+slen > ans ? plen+slen : ans;

        printf("%d\n",ans);
    }

    return 0;
}
