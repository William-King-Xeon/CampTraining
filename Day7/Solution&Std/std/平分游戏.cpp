#include <bits/stdc++.h>

using namespace std;
long long sum;

long long ans;
long long a[1000005],b[1000005];


bool boo[1000005];

int n,k;

int main()
{
	freopen("game1.in","r",stdin);
	freopen("game1.out","w",stdout);
    scanf("%d %d",&n,&k); 
    for (int i=0;i<n;i++)
    {
      scanf("%lld",&a[i]);
      sum+=a[i];
    }
    if (sum%n!=0)
    {
    	printf("gg\n");
		return 0; 
    }
    long long avg=sum/n;
    bool z=false;
    for (int i=0;i<n;i++)
    {
    	a[i]-=avg;
    	if (a[i]!=0) z=true;
    }
    if (k==n) 
    {
    	if (z==true) printf("gg\n");
    	else printf("0\n");
		return 0;
    }
    memset(boo,false,sizeof(boo));
	for (int i=0;i<n;i++)
	if (boo[i]==false)
	{
		int now=i;
		int num=0;
		long long sum=0;
		while (boo[now]==false)
		{
			b[++num]=b[num-1]+a[now];
			boo[now]=true;
			now=(now+k+1)%n;
		}
	
		if (b[num]%n!=0)
    	{
    		printf("gg\n");
			return 0; 
   	    }
   	    sort(b+1,b+num+1);
   	    long long  y=b[(1+num)/2];
   	    for (int j=1;j<=num;j++)
   	    {
   	    	ans+=abs(-y+b[j]);
   	    }
			
	}
	printf("%lld\n",ans);
	return 0;
}

