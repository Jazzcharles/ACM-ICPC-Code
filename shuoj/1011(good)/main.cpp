#include<bits/stdc++.h>
using namespace std;
int n,k,ans,a[20];
bool ok(int x){
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0) return 0;
	}
	return 1;
}

void dfs(int num,int sum,int cnt){
	if(num==k && ok(sum)){
		ans++;
	}
	else{
		for(int i=cnt;i<n;i++){
			dfs(num+1,sum+a[i],i+1);
		}
	} 
}

int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dfs(0,0,0);
	cout<<ans<<endl;
	return 0;
}
