#include <bits/stdc++.h>
#define MP(a,b) make_pair(a,b)
using namespace std;
typedef pair<int,int> PII;
typedef pair<int,PII> PIII;
vector<PIII>G;
const int maxn=1e5+5;
int Father[maxn],Rank[maxn];

void init(int n){
	for(int i=0;i<=n;i++){
		Father[i]=i;     
		Rank[i]=0;
	}
}

int find(int x){
	if(Father[x]!=x){
		Father[x]=find(Father[x]);
	}
	return Father[x];
}

//根节点层数相同或者同为单节点时，数字小的为父节点。
int unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return 0;
	if(Rank[x]<Rank[y])
		Father[x]=y;
	else{
		Father[y]=x;
		if(Rank[x]==Rank[y]) Rank[x]++;
	} 
	return 1;
} 
bool same(int x,int y){
	if(find(x)==find(y)) return 1;
	return 0;
}


void init_G(){
	G.clear();
}

void add_edge(int u,int v,int d){
	G.push_back(MP(d,MP(u,v)));
}

int Kruskal(int n){
	init(n);
	sort(G.begin(),G.end());
	int m=G.size(),num=0,ans=0;
	for(int i=0;i<m;i++){
		PIII p=G[i];
		int x = p.second.first;
		int y = p.second.second;
		int d = p.first;
		if(unite(x,y)){
			num++;
			ans+=d;
		}
		if(num==n-1) break;
	}
	return ans;
} 
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n) && n)
	{
		init_G();
		for(int i=0;i<n*(n-1)/2;i++){
			int x,y,d;
			scanf("%d%d%d",&x,&y,&d);
			add_edge(x,y,d);
			add_edge(y,x,d);
		}
		int ans=Kruskal(n);
		cout<<ans<<endl;
	}
	
	
	
	return 0;
}
