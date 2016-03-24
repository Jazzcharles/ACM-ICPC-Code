#include<iostream>
using namespace std;
int a[1005][1005],dp[1005][1005];
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			cin>>a[i][j];
		}
	}
	
	
	return 0;
}
5
1  1  1  2
   33 33 33
      33 33
         33
