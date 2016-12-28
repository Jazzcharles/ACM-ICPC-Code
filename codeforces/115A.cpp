#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;

int vis[maxn],a[maxn],cnt,ans;
vector<int> fa[maxn];

void dfs(int cur,int k){
	cnt=max(cnt,k);
	//vis[cur]=1;
	//cout<<cur<<' '<<k<<endl; 
	for(int i=0;i<fa[cur].size();i++){
		int x=fa[cur][i];
		if(!vis[x]){
			vis[x]=1;
			dfs(x,k+1);			
		}

	}
}
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=-1) fa[a[i]].push_back(i);
		else vis[i]=-1;
	}
	//for(int i=1;i<=n;i++) cout<<fa[i].size()<<' ';cout<<endl;
	ans=cnt=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==-1){
			cnt=0;
			dfs(i,0);
			ans=max(ans,cnt);			
		}

	} 
	cout<<++ans<<endl; 
	
	
	return 0;
}
/*
5
-1
1
2
1
-1




2
2
-1

*/
