#include<bits/stdc++.h>
using namespace std;
const int maxn = 100;
int p[maxn];
int n;
int res[maxn],vis[maxn];
	
void init(){
	p[0]=p[1]=0;
	for(int i = 2 ; i <= 100 ;  i++)
	{
		int f = 1;
		for(int j = 2 ; j <= i/2 ; j++){
			if(i%j==0) f=0;
		} 
		if(f) p[i] = 1;
		else p[i] = 0;
	} 
}


void dfs(int cur,int cnt){
	//cout<<cur<<endl;
	if(cnt == n){
		if(p[1+cur]){
			for(int i = 0; i < n ; i++){
				if(i != n-1) cout<<res[i]<<' ';
				else cout<<res[i]<<endl;
			}			
		}
	}
	for(int i = 1; i <= n ; i++){
		if(!vis[i] && p[i+cur]) {
			vis[i] = 1;
			res[cnt] = i;
			dfs(i,cnt+1);
			//cout<<6666666<<' '<<cnt<<endl;
			vis[i] = 0;
		} 
	}
}

int main(){
	init();
	while(cin>>n){
		vis[1] = 1;
		res[0] = 1;
		int ca = 1;
		cout<<"Case "<<ca++<<":"<<endl; 
		dfs(1,1);		
	}

	
	
	return 0;
} 
