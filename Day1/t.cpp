#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int n,m,num[1005];

int main()
{
	while(~scanf("%d%d",&n,&m))
	{
		memset(num,0,sizeof(num));
		for (int i=1;i<=n;i++) num[i]=i;
		for (int i=1;i<m;i++) next_permutation(num+1,num+1+n);
		for (int i=1;i<n;i++) printf("%d ",num[i]);
        printf("%d\n",num[n]);
	}
	return 0;
}
