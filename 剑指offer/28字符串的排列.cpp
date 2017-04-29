#include<bits/stdc++.h>
using namespace std;
int a[100],n,b[100],v[100]; 

 
void print(){
	for(int i = 1 ; i <= n ; i++) cout<<a[i]<<' ';cout<<endl;
}
void dfs(int cur){
	if(cur == n){
		print();
		return ;
	}
	for(int i = cur;i<=n;i++){
		swap(a[cur],a[i]);
		dfs(cur+1);
		swap(a[cur],a[i]);
	}	
}
int main(){
	cin>>n;
	for(int i = 1 ; i <= n ;i++){
		cin>>a[i];
	}
	dfs(1);
	return 0;
}
/*
4
1 2 3 4
*/
