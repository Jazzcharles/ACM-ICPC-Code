#include <iostream>
using namespace std;
const int maxn=1e2+5;
int dp[maxn][maxn],a[maxn];
int main(int argc, char** argv) {
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	a[i+1]=a[0];
	for(int i=0;i<n;i++){
		for(int j=i-1;j>=0;j--){
			 if(i-j==1) dp[j][i]=;
		}
	}
	return 0;
}
