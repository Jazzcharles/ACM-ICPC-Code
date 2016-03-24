#include<iostream>
#include<queue>
#include<cstring>
#define MP(a,b) make_pair(a,b)
using namespace std;
const int maxn=1e6+5;
int vis[maxn],s,t;
typedef pair<int,int> PII;
int ok(int num){
	if(num>=0 && num<=100000) return 1;
	return 0;
}
int bfs(int cur){
	queue<PII> q;
	q.push(MP(cur,0));
	vis[cur]=1;
	while(!q.empty()){
		PII temp=q.front();q.pop();
		int p=temp.first;int k=temp.second;
		if(p==t) return k;
		if(ok(p-1) && !vis[p-1]){
			vis[p-1]=1;q.push(MP(p-1,k+1));
		}
		if(ok(p+1) && !vis[p+1]){
			vis[p+1]=1;q.push(MP(p+1,k+1)); 
		}
		if(ok(2*p) && !vis[2*p]){
			vis[2*p]=1;q.push(MP(2*p,k+1));
		}
	}

int main(){
	while(cin>>s>>t)
	{
		memset(vis,0,sizeof(vis));
		cout<<bfs(s)<<endl;	
	}
	
	
	return 0;
} 
