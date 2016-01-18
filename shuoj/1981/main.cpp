#include <iostream>
using namespace std;
const int maxn=1e8;
int main(int argc, char** argv) {
	int n,m,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&n,&m);
		if(n<2) {cout<<0<<endl;continue;}
		if(m>n){
			int temp=n-m;
			cout<<n/2-temp/2<<endl;continue; 
		}
		else{
			
		}
		
	}
	return 0;
}
