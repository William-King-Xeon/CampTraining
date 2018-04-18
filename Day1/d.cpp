#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

map<string,int> cnt;

int n;
string st;

int main()
{
    cin >> n;

    while (n!=0)
    {
        cnt.clear();
        int maxcnt=0;
        string maxst;
        for (int i=1;i<=n;i++)
        {
            cin >> st;
            cnt[st]++;
            if (cnt[st]>maxcnt)
            {
                maxcnt=cnt[st];
                maxst=st;
            }
        }
        cout << maxst << endl;
        cin >> n;
    }

    return 0;
}
