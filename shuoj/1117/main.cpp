#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int a[10][10],n,ans=0;
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>a[i][j];
			if(i+j==n-1 || i==j)
				ans+=a[i][j];
		}
	}
	cout<<ans<<endl;
	return 0;
}
