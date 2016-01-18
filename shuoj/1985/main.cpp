#include <iostream>
#include <algorithm> 
#define INF 0x3f3f3f3f
using namespace std;

int a[30],dp[30];

int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
	
	sort(a,a+n);
	if(n==3){
		cout<<a[0]+a[1]+a[2]<<endl;
	}
	else if(n==2){
		cout<<a[1]<<endl;
	}
	else if(n==1){
		cout<<a[0]<<endl;
	}
	else{	
		int cnt=0;
		dp[1]=a[1]; 
		dp[2]=a[0]+a[1]+a[2];
		for(int i=3;i<n;i++){
			dp[i]=min(dp[i-1]+a[0]+a[i],dp[i-2]+a[i]+a[0]+2*a[1]);
		}
		cout<<dp[n-1]<<endl;
	}
	
	}
	return 0;
}
