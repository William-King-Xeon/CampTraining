#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

const int maxn=1e5+100;
int N,M,g[maxn],cur[maxn],A[maxn];
bool vis[maxn];
queue <int> Q;

int main()
{
    scanf("%d%d",&N,&M);
    for (int i=1; i<=N; ++i) scanf("%d",&A[i]);
    memset(g,0,sizeof(g));
    memset(cur,0,sizeof(cur));
    memset(vis,0,sizeof(vis));
    while(!Q.empty()) Q.pop();
    for (int i=1; i<=N; ++i) ++g[A[i]];
    for (int i=1; i<=N; ++i)
    {
        if (!vis[A[i]])
        {
            if (!Q.empty() && cur[Q.front()]==g[Q.front()]) Q.pop();
            Q.push(A[i]);
            vis[A[i]]=1;
        }
        ++cur[A[i]];
    }
    int ret=0;
    for (int i=1; i<=M; ++i)
        ret+=(g[i]>0);
    printf("%d %d\n",ret,(int)Q.size());
    return 0;
}

