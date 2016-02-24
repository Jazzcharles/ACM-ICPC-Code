#include<iostream>
using namespace std;
int a[105];	
int main(){
	int n;
	cin>>n;
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];sum+=a[i];
	}	
	int cnt=0;
	int ave=sum/n;
	for(int i=1;i<n;i++){
		if(a[i]<ave){
			cnt++;
			a[i+1]-=ave-a[i];
		}
		else if(a[i]>ave){
			cnt++;
			a[i+1]+=a[i]-ave;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
