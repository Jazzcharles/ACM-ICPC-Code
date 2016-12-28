#include<bits/stdc++.h>
using namespace std;


const int maxn=1e5+500;
char a[maxn];
int main(){
	int n,s,t;
	cin>>n>>s>>t;
	scanf("%s",a+1);
	s=min(s,t);
	t=max(s,t);
	if(a[s]==a[t]) cout<<0<<endl;
	else cout<<1<<endl;
	
	
	
	return 0;
} 
