#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+500;
int n;
vector<int> G[maxn];
int main(){
	cin>>n;
	for(int i = 0 ; i < n-1 ; i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u); 
	}
	
	
	
	
	return 0;
}
