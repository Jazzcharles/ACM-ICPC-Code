#include<bits/stdc++.h>
using namespace std;
int n,a[100];
int check(){
	int l=0,r=n-1,ans=0;
	if(a[l]<a[r]) return a[l];
	int flag = 0;
	while(l+1<r){
		int mid = (l+r)>>1;
		cout<<l<<' '<<r<<' '<<mid<<endl;
		if(a[mid] == a[l] && a[l] == a[r]) flag = 1;
		if(a[mid]>=a[l]) ans=mid,l=mid;
		else if(a[mid]<=a[r]) ans=mid,r=mid;
	}
	cout<<l<<' '<<r<<' '<<flag<<endl;
	//	if(flag) //Ë³Ğò 
	return a[r]; 
}

int main(){
	cin>>n;
	for(int i= 0 ; i<n ; i++) cin>>a[i];
	cout<<check()<<endl;
	
	
	
	return 0;
}
