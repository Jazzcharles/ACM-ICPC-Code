#include<iostream>
#include<cmath>
using namespace std;

int a[10],b[10];
int main(){
	while(cin>>a[8]){
		
		for(int i=7;i>=0;i--)
			cin>>a[i];
		int f=0;
		for(int i=0;i<=8;i++){
			if(a[i]) f=1;
		} 
		if(!f){
			cout<<0<<endl;
			continue;
		}
		int cnt=0;
		for(int i=8;i>=0;i--){
			if(a[i]) {
				if(!cnt){
					if(a[i]!=1) {
						if(a[i]==-1) cout<<"-";
						else cout<<a[i];
					}
					if(i && i!=1) cout<<"x^"<<i;
					else if(i==1) cout<<"x";
					cnt++;
				}
				else{
					if(a[i]>0) cout<<" + ";
					else cout<<" - ";
					{
						if(!i) cout<<abs(a[i]);
						else if(abs(a[i])!=1) cout<<abs(a[i]); 
						if(i && i!=1) cout<<"x^"<<i;
						else if(i==1) cout<<"x";					
					}
				} 

			}
			 
		}
		cout<<endl;
	}
	
	
	return 0;
}
