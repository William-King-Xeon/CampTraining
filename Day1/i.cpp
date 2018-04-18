#include <cstdio>
#include <cstring>

int x,y;
char s[10005];

int main()
{
    scanf("%s",s);

    while (s[0]!='0')
    {
        x=0;
        for (int i=0;i<strlen(s);i++)
            x+=s[i]-'0';
        while (x/10!=0)
        {
            y=0;
            while (x!=0)
            {
                y+=x%10;
                x/=10;
            }
            x=y;
        }
        printf("%d\n",x);
        scanf("%s",s);
    }

    return 0;
}
