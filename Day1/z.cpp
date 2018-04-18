#include <cstdio>

int a;
bool ok=true;

int main()
{
    for (int i=1;i<=3;i++)
    {
        scanf("%d",&a);
        if (a<=168) printf("CRASH %d\n",a),ok=false;
    }
    if (ok) printf("NO CRASH\n");
}
