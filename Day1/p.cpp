#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int n;
string st;

int main()
{
    scanf("%d",&n);

    for (int i=1;i<=n;i++)
    {
        cin >> st;
        int j=0;

        while (j<st.size())
        {
            int cnt=1;
            while (st[j]==st[j+1]&&j<st.size()) cnt++,j++;
            if (cnt==1) printf("%c",st[j]); else printf("%d%c",cnt,st[j]);
            j++;
        }

        printf("\n");
    }

    return 0;
}
