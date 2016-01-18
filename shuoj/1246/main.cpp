#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
vector<pair<double, PII> > G;
const int maxn=1e5;
int Father[maxn],Rank[maxn];
struct code{
	int x,y,z;
}a[maxn];
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


void init_G() {
	G.clear();
}
void add_edge(int u, int v, double d) {
	G.push_back(make_pair(d, make_pair(u, v)));
}
double Kruskal(int n) {
	init(n);	
	sort(G.begin(), G.end());
	int m = G.size();
	int num = 0;double ret = 0;
	for (int i = 0; i < m; i++) {
		pair<double, PII> p = G[i];
		int x = p.second.first;
		int y = p.second.second;
		double d = p.first;
		if (unite(x, y)) {
			num++;
			ret += d;
		} 
		if (num == n - 1) break;
	}
	return ret;
}

int main(int argc, char** argv) {
	int t;
	cin>>t;
	while(t--)	
	{
		init_G();
		int n;cin>>n;
		for(int i=1;i<=n;i++){
			int x,y,z;
			scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);		
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				double s=sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y)+(a[i].z-a[j].z)*(a[i].z-a[j].z));
				add_edge(i,j,s);
				add_edge(j,i,s);
			}
		}
		printf("%.2f\n",Kruskal(n));
	}
	return 0;
}
