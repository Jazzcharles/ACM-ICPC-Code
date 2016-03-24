#include<iostream>
#include<cstring>
using namespace std;
string s[1005];
int f,vis[1005],n;
void dfs(char ch){
	if(f) return ;
	if(ch=='m') {
		f=1;return ;
	}
	for(int i=0;i<n-1;i++){
		if(s[i][0]==ch && !vis[i]){
			vis[i]=1;
			dfs(s[i][s[i].length()-1]);
	//		vis[i]=0;
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	while(cin>>s[0])
	{
		n=1;
		while(cin>>s[n++]){
			memset(vis,0,sizeof(vis));
			if(s[n-1]=="0"){
				f=0;
				dfs('b');
				if(f) cout<<"Yes."<<endl;
				else cout<<"No."<<endl;
				for(int i=0;i<n;i++) s[i].clear();
			}
			
		}
	
	}
	
	return 0;
}
