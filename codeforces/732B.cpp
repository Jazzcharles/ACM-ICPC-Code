#include<bits/stdc++.h>
using namespace std;

int a[1005];
int main(){
	int n,x=0,k;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	int temp=k-a[0];
	for(int i=1;i<n;i++){
		if(a[i]<temp) x+=temp-a[i],a[i]=temp;
		temp=k-a[i];
	//	cout<<a[i]<<' '<<temp<<endl;
	} 
	cout<<x<<endl;
	for(int i=0;i<n;i++) cout<<a[i]<<' ';cout<<endl;
	
	return 0;
} 
