#include <iostream>
#include <cstdio>
using namespace std;

const int prime1=1000007;
const int prime2=10000007;

struct HASH
{
	int vl1,vl2,cnt;
} _hash[prime1];

int n,a[7],p1[7],p2[7];

int hash_push(int num1,int num2)
{
	int tmp=num1%prime1;
	while ((_hash[tmp].vl1!=num1||_hash[tmp].vl2!=num2)&&_hash[tmp].cnt!=0)
		tmp=(tmp+1)%prime1;
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
	int tmp=num1%prime1;
	while ((_hash[tmp].vl1!=num1||_hash[tmp].vl2!=num2)&&_hash[tmp].cnt!=0)
        tmp=(tmp+1)%prime1;
	return _hash[tmp].cnt;
}

int CalcHashCW(int p,int MOD)
{
	int ret=0;
    for (int i=1;i<=6;i++) ret=(ret*p+a[i])%MOD;
	return ret;
}

int CalcHashAC(int p,int MOD)
{
    int ret=0;
    for (int i=6;i>=1;i--) ret=(ret*p+a[i])%MOD;
	return ret;
}

int main()
{
    p1[0]=p2[0]=1;
    for (int i=1;i<=6;i++) p1[i]=p1[i-1]*31%prime1;
    for (int i=1;i<=6;i++) p2[i]=p2[i-1]*37%prime2;

	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=6;j++) scanf("%d",&a[j]);

		bool FIND=false;
        int hashnum1=CalcHashCW(31,prime1),hashnum2=CalcHashCW(37,prime2);
		for (int j=1;j<=6;j++)
        {
			if (hash_find(hashnum1,hashnum2)) { FIND=true;break; }
            hashnum1=(hashnum1*31%p1[6]+a[j])%prime1;
            hashnum2=(hashnum2*37%p2[6]+a[j])%prime2;
        }

		if (!FIND)
        {
            hashnum1=CalcHashAC(31,prime1),hashnum2=CalcHashAC(37,prime2);
			for (int j=6;j>=1;j--)
            {
				if (hash_find(hashnum1,hashnum2)) { FIND=true;break; }
                hashnum1=(hashnum1*31%p1[6]+a[j])%prime1;
                hashnum2=(hashnum2*37%p2[6]+a[j])%prime2;
            }
        }

		if (FIND)
		{
			printf("Twin snowflakes found.\n");
			return 0;
		}
		else hash_push(CalcHashCW(31,prime1),CalcHashCW(37,prime2));
	}
	printf("No two snowflakes are alike.\n");
	return 0;
}
