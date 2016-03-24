#include<iostream>
#include<cstring>
using namespace std;
const int maxn=1e2+5;
int dp[maxn][maxn],w[maxn],c[maxn],v[maxn];
struct node{
	int a,b,c;
}s[maxn];
int cmp(node x,node y){
	return x.b==y.b?x.c>y.c:x.b<y.b;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m,e;
		cin>>n>>m>>e;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++)
			cin>>s[i].a>>s[i].b>>s[i].c;
		int ans=0;
		sort(s+1,s+1+n,cmp);
		for(int i=1;i<=n;i++){
			for(int j=s[i].b;j<=m;j++){
				for(int k=s[i].a;k<=e;k++){
					dp[j][k]=max(dp[j][k],dp[j-s[i].b][k-s[i].a]+s[i].c);
				}
			}
		}
		
	//	cout<<ans<<endl;
	}
	return 0;
}
