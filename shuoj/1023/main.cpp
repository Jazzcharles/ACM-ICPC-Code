#include <iostream>
using namespace std;
int phi[1000];
void eular(int n){
	for(int i=0;i<n+1;i++)
	  phi[i]=i;
	for(int i=2;i<n+1;i++){
		if(phi[i]==i){
			cout<<phi[i]<<endl;
			for(int j=i;j<1+n;j+=i){
				phi[j]=phi[j]/i*(i-1);
		//		cout<<j<<' '<<phi[j]<<endl;
			}
		}
	}
	
}
int main(int argc, char** argv) {
	int n;
	cin>>n;
	eular(n);
	return 0;
}
