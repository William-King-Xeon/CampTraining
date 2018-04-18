#include <cstdio>
#include <cstring>
#define ULL unsigned long long
#define MIN(a,b) (a<b?a:b)
#define clean(x,v) (memset(x,v,sizeof(x)))

int T;
ULL p[1000005],CWhash[1000005],AChash[1000005];
char str[1000005];

int main()
{
	p[0]=1;
	for (int i=1;i<=1000005;i++) p[i]=p[i-1]*31;

	while (~scanf("%s",str))
	{
		int SLEN=strlen(str);
		if (str[0]=='E') break;

		clean(CWhash,0);clean(AChash,0);

		CWhash[0]=str[0]-'a'+1;
		for (int i=1;i<SLEN;i++) CWhash[i]=(CWhash[i-1]*31+(str[i]-'a'+1));

		AChash[SLEN-1]=str[SLEN-1]-'a'+1;
		for (int i=SLEN-2;i>=0;i--) AChash[i]=(AChash[i+1]*31+(str[i]-'a'+1));

		int maxlen=1;
		for (int middle=0;middle<SLEN;middle++)
		{
			int l=0,r=MIN(middle+1,SLEN-middle)+1;
			while (l+1<r)
			{
				int len=(l+r)/2;
				int start=middle-len+1,end=middle+len-1;

				ULL CW=CWhash[end]-CWhash[start-1]*p[end-start+1],
					AC=AChash[start]-AChash[end+1]*p[end-start+1];
				if (start==0) CW=CWhash[end];

				if (CW==AC) l=len; else r=len;
			}
			if (l*2-1>maxlen) maxlen=l*2-1;
		}

		for (int middle=0;middle<SLEN;middle++)
		{
			int l=0,r=MIN(middle+1,SLEN-middle-1)+1;

			while (l+1<r)
			{
				int len=(l+r)/2;
				int start=middle-len+1,end=middle+len;

				ULL CW=CWhash[end]-CWhash[start-1]*p[end-start+1],
					AC=AChash[start]-AChash[end+1]*p[end-start+1];
				if (start==0) CW=CWhash[end];

				if (CW==AC) l=len; else r=len;
			}
			if (l*2>maxlen) maxlen=l*2;
		}

		printf("Case %d: %d\n",++T,maxlen);
	}
	return 0;
}
