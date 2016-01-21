#include<iostream>
using namespace std;
int eular(int n){
	int res=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			res=res/i*(i-1);
			while(n%i==0)
				n/=i; 
		}
	}
	if(n!=1) res=res/n*(n-1);
	return res;
}
int main(){
	int n;
	while(~scanf("%d",&n) && n)
	{
		printf("%d\n",eular(n));
	}
	return 0; 
} 
