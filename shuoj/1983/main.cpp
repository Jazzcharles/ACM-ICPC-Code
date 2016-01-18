#include <iostream>
using namespace std;
 
int main(int argc, char** argv) {
	int n;
	while(~scanf("%d",&n)) 
	{
		if(n>=5){
		int ans=3,cnt=3;
		for(int i=1;i<=n-2;i++){
			ans*=2;
		}
		for(int i=1;i<=n-4;i++){
			cnt*=2;
		}
		ans+=cnt;
		cout<<ans<<endl; 	
		}
		else if(n==1) cout<<3<<endl;
		else if(n==2) cout<<6<<endl;
		else if(n==3) cout<<6<<endl;
		else if(n==4) cout<<18<<endl; 
		else cout<<0<<endl;
		
	}
	return 0;
}
