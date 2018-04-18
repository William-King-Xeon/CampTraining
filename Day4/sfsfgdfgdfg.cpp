#include<cstdio>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
using namespace std;
vector<int> G[100005];
map<string,int> m;
int T,n,pos[100005],q1,q2,tmp,f[50000005][22][2],fa[100005],rt,tmp2,q; string x,y,guys[100005];

void dfs(int root,int dep){
	f[++tmp][0][0]=dep; f[tmp][0][1]=root; pos[root]=tmp;
	int sz=G[root].size();
	for(int i=0;i<sz;i++)
		dfs(G[root][i],dep+1),f[++tmp][0][0]=dep,f[tmp][0][1]=root;
}

int lca(int l,int r){
	int t1=(int)log2(r-l+1);
	if(f[l][t1][0]<f[l+(1<<t1)-1][(int)log2(r-(l+(1<<t1)-1)+1)][0])
		return f[l][t1][1];
	else return f[l+(1<<t1)-1][(int)log2(r-(l+(1<<t1)-1)+1)][1];
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		if(!m.count(x)) guys[++tmp2]=x,m[x]=tmp2;
		if(!m.count(y)) guys[++tmp2]=y,m[y]=tmp2;
		G[m[x]].push_back(m[y]);
	}
	dfs(1,0);
	for(int j=1;(1<<j)<=tmp;j++)
		for(int i=1;(1<<j)+i-1<=tmp;i++)
			if(f[i][j-1][0]<f[i+(1<<j-1)][j-1][0]){
				f[i][j][0]=f[i][j-1][0];
				f[i][j][1]=f[i][j-1][1];
			}else{
				f[i][j][0]=f[i+(1<<j-1)][j-1][0];
				f[i][j][1]=f[i+(1<<j-1)][j-1][1];
			}
	cin>>q;
	for(int i=0;i!=q;i++){
		cin>>x>>y;
		cout<<guys[lca(min(pos[m[x]],pos[m[y]]),max(pos[m[x]],pos[m[y]]))]<<endl;
	}
}
