#include <iostream>
using namespace std;
const int maxn=1e5;
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
int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--){
		int n,m;
		scanf("%d%d",&n,&m);
		init(n);
		for(int i=1;i<=m;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			x--;y--;
			unite(x,y); 
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(find(i)==i)
				cnt++;
			cout<<Rank[i]<<endl;
		}
		cout<<cnt<<endl;
		
	}
	
	
	return 0;
}
