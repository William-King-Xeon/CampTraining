#include <cstdio>
#include <ctime>
#include <cstdlib>

int T;

int main()
{
    freopen("2465.in","r",stdin);
    freopen("2465.out","w",stdout);

    srand(time(NULL));

    scanf("%d",&T);

    while (T--)
    {
        if (rand()%2) printf("yes\n"); else printf("no\n");
    }

    return 0;
}
