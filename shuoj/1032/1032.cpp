#include <bits/stdc++.h>
using namespace std;
#define max 10000000

int phi[max];
void eular(int n){
 for(int i = 0; i<=n;i++) phi[i] = i;
 for(int i = 2; i<=n;i++){
 	if(phi[i] == i)
      for(int j = i;j<=n;j+=i){
      	phi[j] = phi[j] / i * (i-1);
	  }
 }
    
         
 }
int main(int argc, char** argv) {
	int n;
	cin>>n;
	eular(n);
	return 0;
}




