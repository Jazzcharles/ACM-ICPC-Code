#include<iostream>
using namespace std;


int main(){
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			ans+=i;	
		}	
		cout<<ans<<endl<<endl;
	}
	return 0; 
} 
