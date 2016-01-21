#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int maxn=1e5;
int low[maxn],dfn[maxn],cnt_root,root,index;
bool flag[maxn];
vector<int> adj[maxn];
void init(){
	index=0,cnt_root=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(flag,0,sizeof(flag));
	memset(adj,0,sizeof(adj));
}
void dfs(int cur){
	dfn[cur]=low[cur]=++index;
	int size=adj[cur].size();
	for(int i=0;i<size;i++){
		int v=adj[cur][i];
		if(!dfn[v]){
			dfs(v);
			if(cur==1) cnt_root++; 
			else{
				low[cur]=min(low[cur],low[v]);
				if(low[v]>=dfn[cur]) flag[cur]=1;	
			}
		}
		else
			low[cur]=min(low[cur],dfn[v]);
	}
}
int main(int argc, char** argv) {
	int t;
	while(~scanf("%d",&t) && t)
	{
		init();
		int s,v;
		while(scanf("%d",&s) && s){
			while(getchar()!='\n'){
				scanf("%d",&v);
				adj[s].push_back(v);
				adj[v].push_back(s);
			}
		}
		dfs(1);
		int ans=0;
		if(cnt_root>1) ans++;
		for(int i=1;i<=t;i++)
		{
			//cout<<dfn[i]<<' '<<low[i]<<endl;
			if(flag[i]) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
