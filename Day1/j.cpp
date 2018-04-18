#include <cstdio>
#include <cstring>

int STEP,MOD,cnt[100005],seed[100005];

int main()
{
    while (~scanf("%d%d",&STEP,&MOD))
    {
        seed[0]=0;
        memset(cnt,0,sizeof(cnt));
        cnt[0]=1;

        bool ok=true;
        for (int i=1;i<MOD;i++)
        {
            seed[i]=(seed[i-1]+STEP)%MOD;
            if (cnt[seed[i]]!=0)
            {
                ok=false;
                break;
            }
        }

        printf("%10.d%10.d    ",STEP,MOD);

        if (ok) printf("Good Choice\n\n");
            else printf("Bad Choice\n\n");
    }

    return 0;
}
