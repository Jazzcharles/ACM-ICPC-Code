#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=1e5+5;
long long a[maxn],dpl[maxn],dpr[maxn];
int main(){
	int n;
	while(cin>>n&&n)
	{
		memset(dpl,0,sizeof(dpl));
		memset(dpr,0,sizeof(dpr));
		for(int i=0;i<n;i++){
			cin>>a[i];
			dpl[i]=dpr[i]=i;
		}
		for(int i=0;i<n;i++){
			while(dpl[i]>0 && a[dpl[i]-1]>=a[i]) dpl[i]=dpl[dpl[i]-1];
		}
		for(int i=n-1;i>=0;i--){
			while(dpr[i]<n-1 && a[dpr[i]+1]>=a[i]) dpr[i]=dpr[dpr[i]+1];
		}
		//for(int i=0;i<n;i++) cout<<dpl[i]<<' ';cout<<endl;
		//for(int i=0;i<n;i++) cout<<dpr[i]<<' ';cout<<endl;
		long long ans=0;
		for(int i=0;i<n;i++){
			ans=max(ans,a[i]*(dpr[i]-dpl[i]+1));
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
