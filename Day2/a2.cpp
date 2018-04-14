#include <iostream>
#include <cstdio>
using namespace std;

const int prime=5000007;
struct HASH
{
	int vl1,vl2,cnt;
} _hash[prime];

int n,a[7];

int hash_push(int num1,int num2)
{
	int tmp=num1%prime;
	while ((_hash[tmp].vl1!=num1||_hash[tmp].vl2!=num2)&&_hash[tmp].cnt!=0)
		tmp=(tmp+1)%prime;
	if (_hash[tmp].vl1==num1&&_hash[tmp].vl2==num2) return ++_hash[tmp].cnt;
		else
		{
			_hash[tmp].vl1=num1;
			_hash[tmp].vl2=num2;
			return _hash[tmp].cnt=1;
		}
	return 0;
}

int hash_find(int num1,int num2)
{
	int tmp=num1%prime;
	while ((_hash[tmp].vl1!=num1||_hash[tmp].vl2!=num2)&&_hash[tmp].cnt!=0) tmp=(tmp+1)%prime;
	return _hash[tmp].cnt;
}

int CalcHashCW1(int start)
{
	int ret=0;
	for (int i=start;i<=6;i++) ret=(ret*31%prime+a[i])%prime;
	for (int i=1;i<start;i++) ret=(ret*31%prime+a[i])%prime;
	return ret;
}

int CalcHashCW2(int start)
{
	int ret=0;
	for (int i=start;i<=6;i++) ret=(ret*37%prime+a[i])%prime;
	for (int i=1;i<start;i++) ret=(ret*37%prime+a[i])%prime;
	return ret;
}

int CalcHashCCW1(int end)
{
	int ret=0;
	for (int i=end;i>=1;i--) ret=(ret*31%prime+a[i])%prime;
	for (int i=6;i>end;i--) ret=(ret*31%prime+a[i])%prime;
	return ret;
}

int CalcHashCCW2(int end)
{
	int ret=0;
	for (int i=end;i>=1;i--) ret=(ret*37%prime+a[i])%prime;
	for (int i=6;i>end;i--) ret=(ret*37%prime+a[i])%prime;
	return ret;
}

int main()
{
	freopen("1814.in","r",stdin);
	freopen("1814.out","w",stdout);
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=6;j++)
			scanf("%d",&a[j]);

		bool FIND=false;
		for (int j=1;j<=6;j++)
			if (hash_find(CalcHashCW1(j),CalcHashCW2(j)))
			{
				FIND=true;
				break;
			}
		if (!FIND)
			for (int j=1;j<=5;j++)
				if (hash_find(CalcHashCCW1(j),CalcHashCCW2(j)))
				{
					FIND=true;
					break;
				}
		if (FIND)
		{
			printf("Twin snowflakes found.\n");
			return 0;
		}
		else hash_push(CalcHashCW1(1),CalcHashCW2(1));
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}
