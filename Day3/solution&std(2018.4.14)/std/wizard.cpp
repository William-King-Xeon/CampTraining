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

const int maxn=300+10;
int N,A[maxn],dp[maxn][maxn];

int dfs(int le,int ri)
{
    if (le==ri) return 0;
    if (dp[le][ri]!=-1) return dp[le][ri];
    int ret=min( A[le]+dfs(le+1,ri), A[ri]+dfs(le,ri-1) );
    For(k,le+1,ri-1)
    {
        int cost=A[k]+max( dfs(le,k-1), dfs(k+1,ri) );
        ret=min(ret,cost);
    }
    dp[le][ri]=ret;
    return ret;
}

int main()
{
    scanf("%d",&N);
    For(i,1,N) scanf("%d",&A[i]);
    memset(dp,255,sizeof(dp));
    printf("%d\n",dfs(1,N));
    return 0;
}

