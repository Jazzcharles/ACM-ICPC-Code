#include <iostream>
#include <cstdio>
using namespace std;
const int maxn=10000;
int a[maxn],dp[maxn],nex[maxn];
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		nex[0]=0;	
		for(int i=0;i<n;i++){
			int temp=0,index=i;
			dp[i]=1;
			for(int j=i-1;j>=0;j--){
				if(a[j]>=a[i] && temp<dp[j]){
					temp=dp[j];
					index=j;
				}
			}
			dp[i]=temp+1,nex[i]=index;
		}
		int cnt=0;
		for(int i=n-1;i>=0;i--){
			if(!a[i]) continue;
			for(int j=i;a[j];j=nex[j]){
				a[j]=0;
//				cout<<j<<' '<<nex[j]<<endl;
			}
			cnt++; 
		}
		cout<<cnt<<endl;

	}
	return 0;
}

