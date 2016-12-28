#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+500;
vector<int> G[maxn];
int n,m,ans;
int a[maxn],vis[maxn],f[maxn];
void addedge(int u,int v){
	G[u].push_back(v);
	G[v].push_back(u);
}

void dfs(int cur,int cnt){//cur:当前点，cnt:连续喵的数量 
	if(cnt>m) return ;
	if(vis[cur]) return ;
	vis[cur]=1;
	int flag=1;//flag=1 叶子 
	for(int i=0;i<G[cur].size();i++){
		if(!vis[G[cur][i]]) flag=0;
	}
	for(int i=0;i<G[cur].size();i++){
		int v=G[cur][i];
		if(a[v]){
			dfs(v,cnt+1);
		}
		else{
			dfs(v,0);
		}
	}
	if(flag && cnt<=m) ans++;
}

int main(){
	ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		addedge(u,v); 
	}
	dfs(1,a[1]);
	cout<<ans<<endl;
	
	return 0;
}
/*

4 1
1 1 0 0
1 2
1 3
1 4



7 1
1 0 1 1 0 0 0
1 2
1 3
2 4
2 5
3 6
3 7
*/
