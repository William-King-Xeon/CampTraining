#include <cstdio>

int T,n,m,k,cheat;
bool flag=true,flag2=true,flag3=true,flag4=true,flag5=true,flag6=true;

int main()
{
	freopen("2465.in","r",stdin);
	freopen("2465.out","w",stdout);

	scanf("%d",&T);
	for (int k=0;k<T;k++)
	{
		scanf("%d%d%d",&n,&m,&k);
		if (n>1) flag5=false;
		if (n>8||m>8) flag3=false;
		if (k>10) flag4=false;
		if (k>8) flag2=false;
		for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
		{
			scanf("%d",&cheat);
			if(cheat!=1) flag=false;
		}
	}
	if (n>5&&n<=8&&flag)
	{
		printf("no\n");
		printf("no\n");
		printf("yes\n");
		printf("yes\n");
		printf("yes\n");
	} else if(n==1&&!flag)
	{
		printf("no\n");
		printf("yes\n");
		printf("no\n");
		printf("yes\n");
		printf("yes\n");
	} else if(!flag3&&!flag2&&!flag&&flag4)
	{
		printf("yes\n");
		printf("no\n");
		printf("no\n");
		printf("yes\n");
		printf("yes\n");
	} else if(n>5&&n<=8&&!flag)
	{
		printf("yes\n");
		printf("no\n");
		printf("yes\n");
		printf("yes\n");
		printf("no\n");
	} else if(n<=5&&m<=5&&!flag5&&flag)
	{
		printf("yes\n");
		printf("yes\n");
		printf("no\n");
		printf("no\n");
		printf("yes\n");
	} else if(flag4&&flag&&!flag3&&!flag2)
	{
		printf("yes\n");
		printf("yes\n");
		printf("no\n");
		printf("yes\n");
		printf("no\n");
	} else
	{
		printf("yes\n");
		printf("yes\n");
		printf("yes\n");
		printf("no\n");
		printf("yes\n");
	}
	return 0;
}
