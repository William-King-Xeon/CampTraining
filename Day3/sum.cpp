#include <cstdio>

typedef long long LL;

LL n,l,r,U,V,m;

LL Calc(LL a1,LL d,LL &l,LL &r)
{
    LL an=a1+(r-l)*d;
    if (U>an||V<a1) return 0;

    /* 在这个等差数列内找到u和v使得U <= au,...,av <= V */
    LL u=( V>=an ? r-l : (V-a1)/d ),
       v=( U<=a1 ? 0 : (U-1-a1)/d+1 );

    /* 等差数列前n项和 Sn=n(a1+an)/2 */
    LL auPLUSav=/* au: */a1+u*d + /* av: */a1+v*d, /* 求au+aV */
       N=v-u+1;/* 求n */
    return N * auPLUSav / 2;
}

/*
    a1:此等差序列的第一个值
    d:此等差序列的公差
*/
LL Query(LL a1,LL d,LL l,LL r,LL s,LL t)
{
    /* 与线段树查询类似 */
    if (l>t||r<s) return 0;
    if (s<=l&&r<=t) return Calc(a1,d,l,r);

    LL mid=(l+r)/2;
    return Query(a1   , d*2 , l     , mid , s , t)+
           Query(a1+d , d*2 , mid+1 , r   , s , t);
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for (int i=1;i<=m;i++)
    {
        scanf("%lld%lld%lld%lld",&l,&r,&U,&V);
        printf("%lld\n",Query(1,1,1,n,l,r));
    }
    return 0;
}
