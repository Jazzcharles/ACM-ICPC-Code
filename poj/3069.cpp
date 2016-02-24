#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[2005];
int main(){
	int r,n;
	while(~scanf("%d%d",&r,&n)){
		if(n==-1 && r==-1) break;
		for(int i=0;i<n;i++)
			scanf("%d",a+i);
		sort(a,a+n);
		int ans=0;
		for(int i=0;i<n;i++){
			i=upper_bound(a,a+n,a[i]+r)-a-1;
			i=upper_bound(a,a+n,a[i]+r)-a-1;
			ans++;
		}
		cout<<ans<<endl; 
	}
	return 0;
} 
