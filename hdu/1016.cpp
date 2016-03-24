#include<iostream>
#include<cstring>
#define CLR(a,b) memset(a,b,sizeof(a))
using namespace std;
const int MAXN=2e2+5;
int n,phi[MAXN],ans[MAXN],fa[MAXN],vis[MAXN];
void eular(){
	for(int i = 0; i<MAXN;i++) phi[i] = i;
	for(int i = 2; i<MAXN;i++)
		 if(phi[i] == i)
			 for(int j = i+i;j<MAXN;j+=i)
				 phi[j] = 0;
}
void print(int cur){
	int n=0;
	while(cur!=1){
		ans[n++]=cur;
		cur=fa[cur];
	}
	cout<<1;
	for(int i=n-1;i>=0;i--)
		cout<<' '<<ans[i];
	cout<<endl;
}
void dfs(int cur,int k){
	if(k==n && phi[cur+1]){
		print(cur);
	}
	//cout<<cur<<' '<<k<<endl;
	for(int i=2;i<=n;i++){
		if(phi[cur+i] && !vis[i]){
			vis[i]=1;
			fa[i]=cur; 
			dfs(i,k+1);
			vis[i]=0;
		}
	}
}

void init(){
	CLR(ans,0);CLR(fa,0);CLR(vis,0);
}
int main(){
	int ca=1;
	eular();
	while(cin>>n)
	{
		cout<<"Case "<<ca++<<":"<<endl;
		init();
		dfs(1,1);
		cout<<endl;
	}
	return 0;
}
