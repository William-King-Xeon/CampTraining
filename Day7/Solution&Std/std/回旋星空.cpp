#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int x[maxn];
int y[maxn];
map<int,int>maple;
int main()
{
    freopen("space10.in","r",stdin);
    freopen("space10.out","w",stdout);
    int t,n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d %d",&x[i],&y[i]);
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            maple.clear();
            for(int j=0;j<n;j++)
            {
                if(i==j)
                    continue;
                int dx = (x[i]-x[j])*(x[i]-x[j]);
                int dy = (y[i]-y[j])*(y[i]-y[j]);
                maple[dx+dy]++;
            }
            for(auto &cnt: maple)
            {
                int tmp = cnt.second;
                if(tmp>=2)
                    ans += (tmp-1)*tmp/2;
            }
        }
        if(ans==0)
            cout<<"WA"<<endl;
        else
            cout<<ans<<endl;
 
    return 0;
}
