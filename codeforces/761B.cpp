#include<bits/stdc++.h>
using namespace std;


int a[500],b[500],aa[500],bb[500];
int n,L;
int cal(int loc){
	for(int i=loc,j=0;j<n;j++,i=(i+1)%n){
		if(aa[i]!=bb[j]) return 0;		
	}
	return 1;
}
int main(){
	cin>>n>>L;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>b[i];
	for(int i=0;i<n-1;i++) aa[i]=a[i+1]-a[i];
	aa[n-1]=L-(abs(a[n-1]-a[0]));
	
	for(int i=0;i<n-1;i++) bb[i]=b[i+1]-b[i];
	bb[n-1]=L-(abs(b[n-1]-b[0]));
//	for(int i=0;i<n;i++) cout<<aa[i]<<' ';cout<<endl;
//	for(int i=0;i<n;i++) cout<<bb[i]<<' ';cout<<endl;
//	
	
	int f=0;
	for(int i=0;i<n;i++){
		if(cal(i)) {
			f=1;break;
		}
	}
	
	if(f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}
/*
3 8
2 4 6
1 5 7

4 9
2 3 5 8
0 1 3 6

2 95
45 59
3 84

*/
