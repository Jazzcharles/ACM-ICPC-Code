#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,a[100][100],b[100][100];
	cin>>n;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];
			
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			cin>>b[i][j];
			b[i][j]+=a[i][j];
		}
	for(int i=0;i<n;i++)
	{
	
		for(int j=0;j<n;j++){
			if(j) cout<<' ';
			cout<<b[i][j];
		}
		cout<<endl;
	}
			
	return 0;
}
