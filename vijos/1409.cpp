#include<iostream>
#include<algorithm>
using namespace std;
int a[30005];
int main(){
	int m,n;
	cin>>m>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int cnt=0;
	for(int i=1,j=n;i<=j;i++,j--){
	//	cout<<i<<' '<<j<<endl;
		int temp=0;
		while(a[i]+a[j]>m && i!=j){
			temp++;j--;
		}
		cnt+=(temp+1);
	//	cout<<cnt<<endl;
	}
	cout<<cnt<<endl;
	return 0;
}
