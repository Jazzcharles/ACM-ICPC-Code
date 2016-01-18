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

//���ڵ������ͬ����ͬΪ���ڵ�ʱ������С��Ϊ���ڵ㡣
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
	int n,m,p;
	cin>>n>>m>>p;
	init(n);
	while(m--){
		int x,y;
		cin>>x>>y;
		unite(x,y);
	}
	while(p--){
		int x,y;
		cin>>x>>y;
		if(same(x,y))
			cout<<"Yes"<<endl;
		else 
			cout<<"No"<<endl;
	}

	return 0;
}
