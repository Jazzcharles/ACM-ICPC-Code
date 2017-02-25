#include<bits/stdc++.h>
using namespace std;
const int maxn=1e2+500;
vector<int> G[maxn]; 
int vis[maxn];
void add_edge(int u,int v){
	G[u].push_back(v);
}

void dfs(int u){
	for(int i=0;i<G[u].size();i++){
		int v=G[u][i];
		if(!vis[v]){
			vis[v]=1;
			dfs(v);
		}
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<m;i++){
			int u,v;
			char uu,vv,ch;		
			getchar();
			scanf("%c%d%c%c%d",&uu,&u,&ch,&vv,&v);
			if(uu=='m' && vv=='m') {//u V v
				add_edge(u+n,v);
				add_edge(v+n,u);
			} 	
			else if(uu=='m' && vv=='h'){//u V !v
				add_edge(u+n,v+n);
				add_edge(v,u);
			}	
			else if(uu=='h' && vv=='m'){//!u V v 
				add_edge(u,v);
				add_edge(v+n,u+n);
			}
			else{//!u V !v 
				add_edge(u,v+n);
				add_edge(v,u+n);
			}
		}
		int f=0;
//		for(int i=1;i<=n*2;i++){
//			for(int j=0;j<G[i].size();j++){
//				cout<<i<<' '<<G[i][j]<<endl; 
//			}
//		}
		for(int i=1;i<=n;i++){
			int ct=0;
			memset(vis,0,sizeof(vis));
			vis[i]=1;
			dfs(i);
			if(vis[i+n]) ct++;
			memset(vis,0,sizeof(vis));
			vis[i+n]=1;
			dfs(i+n);
			if(vis[i]) ct++;
			if(ct==2) {
				//cout<<"ans = "<<i<<endl;
				f=1;break;
			}
		}
		if(f) puts("BAD");
		else puts("GOOD");
	
	
	}
	



	return 0;
}
/*
2
3 4
m3 h1
m1 m2
h1 h3
h3 m2
2 4
h1 m2
m2 m1
h1 h2
m1 h2
*/
