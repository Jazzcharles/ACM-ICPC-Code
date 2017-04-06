#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+500; 
int p[maxn];
int q[maxn];
int ansp[maxn];
int ansq[maxn];
int st[maxn][2];
int pp,qq,n,mod,ct;
//1:win 0:lose,当前点cur,角色k 
int dfs(int cur,int k){
	cur%=mod;
	ct++;
	if(ct>5) return 0;
	cout<<cur<<endl;
	if(cur == 0) {
		return 0;
	}
	int ct = 0;
	if(k == 0){
		for(int i = 0 ; i < pp ; i++){
			if(dfs(cur+p[i],k^1) == 0) return 1;
		}	
		return 0;	
	} 
	else{
		for(int i = 0 ; i < qq ; i++){
			if(dfs(cur+q[i],k^1) == 0) return 1;
		}
		return 0;	
	}
}

int main(){
	cin>>n;
	cin>>pp;
	mod = n; 
	for(int i = 0 ; i < pp ; i++){
		cin>>p[i];
	}	
	cin>>qq;
	for(int i = 0 ; i < qq ; i++){
		cin>>q[i];
	}
	sort(p,p+pp);
	sort(q,q+qq);
	/* 
	for(int i = 1; i < n ; i++){
		int res = dfs(i,0);
		if(res == 0){
			cout<<"Lose"<<' ';
		}
		else if(res == 1){
			cout<<"Win"<<' ';
		}
		else{
			cout<<"Loop"<<' ';
		}
	}
	*/
	dfs(1,0); 
	return 0;
}
/*
5
2 3 2
3 1 2 3

*/
