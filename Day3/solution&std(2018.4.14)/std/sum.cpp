#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <bitset>
#include <vector>
using namespace std;

#define bll long long
#define dou double
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; ++i)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; --i)
#define Mem(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(b))

long long N,L,R,U,V;
int M;

long long calc(long long a1,long long d,long long &le,long long &ri)
{
    long long an=a1+(ri-le)*d;
    if (U>an || V<a1) return 0;
    long long kr=(V-a1)/d;
    if (kr>ri-le) kr=ri-le;
    long long kl=(U<=a1 ? 0 : (U-1-a1)/d+1);
    long long sum=a1+kl*d+a1+kr*d;
    long long g=kr-kl+1;
    (sum&1) ? g>>=1 : sum>>=1;
    return g * sum;
}

long long query(long long a1,long long d,long long le,long long ri)
{
    if (le>R || ri<L) return 0;
    if (L<=le && ri<=R) return calc(a1,d,le,ri);
    long long mid=(le+ri)>>1;
    long long p=query(a1,d<<1,le,mid);
    long long q=query(a1+d,d<<1,mid+1,ri);
    return p+q;
}

int main()
{
    for (; scanf("%lld%d",&N,&M)!=EOF; )
    {
        For(i,1,M)
        {
            scanf("%lld%lld%lld%lld",&L,&R,&U,&V);
            long long ans=query(1,1,1,N);
            printf("%lld\n",ans);
        }
    }
    return 0;
}
