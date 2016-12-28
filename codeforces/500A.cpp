#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],n,t,flag;
void dfs(int cur,int k){
	if(flag==-1) return ;
	if(k>=n) {
		flag=-1;
		return ;	
	}
	if(cur==t) {
		flag=1;
		return ;
	} 
	dfs(cur+a[cur],k+1);
}
int main(){
	cin>>n>>t;
	flag=0;
	for(int i=1;i<n;i++) cin>>a[i];
	dfs(1,0);
	if(flag==1) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	
	
	return 0;
}
/*

*/
