#include<iostream>
#include<algorithm> 
using namespace std;

int sum,n,tot;
int a[100];
int ans[100];

void dfs(int s,int cur,int index){
	if(s==sum){
		tot=1;
		for(int i=0;i<index;i++){
			if(i) cout<<"+";
			cout<<ans[i];
		}
		cout<<endl;
	}
	for(int i=cur+1;i<=n;i++){
		if(a[i]+s<=sum){
			ans[index]=a[i];
			dfs(s+a[i],i,index+1);
			while(a[i]==a[i+1]) i++;
		}
	}
}
int cmp(int a,int b){
	return a>b;
}
int main(){
	while(cin>>sum>>n,sum&&n)
	{
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1,cmp);
		tot=0;
		cout<<"Sums of "<<sum<<":"<<endl;
		dfs(0,0,0);	
		if(!tot) cout<<"NONE"<<endl;
		
	}
	return 0;
}
