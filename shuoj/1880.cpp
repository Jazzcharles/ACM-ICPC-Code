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

//根节点层数相同或者同为单节点时，数字小的为父节点。
int unite(int x,int y){
	x=find(x);
	y=find(y);
	if(x==y) return 0;
//	if(Rank[x]<Rank[y])
		Father[x]=y;
//	else{
//		Father[y]=x;
//		if(Rank[x]==Rank[y]) 
		Rank[y]+=Rank[x]+1;
//	} 
	return 1;
} 
bool same(int x,int y){
	if(find(x)==find(y)) return 1;
	return 0;
}

int main(){
	int n,m;
	cin>>n>>m;
	init(n); 
	while(m--)
	{
		int q,x,y;
		scanf("%d%d%d",&q,&x,&y);
		if(q==1){
			unite(x,y); 
		}
		else{
			if(same(x,y)){
				printf("Yes %d\n",Rank[x]-Rank[y]);
			}
			else{
				printf("No\n");
			}
		}
	}
	
	return 0;
}
