#include<iostream>
using namespace std;
int a[40][40];
void init(){
		for(int i=1;i<=40;i++){
	 		for(int j=1;j<=i;j++){
	 			if(j==1 || j==i) a[i][j]=1;
	 			else a[i][j]=a[i-1][j]+a[i-1][j-1];
			 }
		 }
} 
int main(){
	int n;
	init();
	while(cin>>n)
	 {
	 	for(int i=1;i<=n;i++){
	 		cout<<a[i][1];
	 		for(int j=2;j<=i;j++){
	 			cout<<' '<<a[i][j]; 
			 }
			 cout<<endl;
		 }
		 cout<<endl;
	 }
	
	
	
	return 0;
} 
