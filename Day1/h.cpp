#include <cstdio>

int main()
{
    printf("n e\n- -----------\n");
    printf("0 1\n1 2\n2 2.5\n");
    double a=2.5;
    for (int i=3;i<=9;i++)
    {
        printf("%d ",i);
        double b=1;
        for (int j=2;j<=i;j++)
            b*=j;
        a=a+(double)1.0/b;
        printf("%.9lf\n",a);
    }
    return 0;
}
