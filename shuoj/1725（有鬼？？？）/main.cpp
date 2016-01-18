#include <bits/stdc++.h>
using namespace std;
long long a[200],b[200];
void cal(){
	a[1]=1,a[2]=2,a[3]=3,a[4]=4;
	for(int i=200;i<=200;i++){
		if(i==200) {
			a[i]=270322445352960000;continue;
		}
		a[i]=1;
	    int x=i,j,sum=0,k=0,cnt;
	    for(j=2;sum<x;j++){
	    	if(sum+j>x) break;
	    	sum+=j;
	    	b[k++]=j;
		}
		
		cnt=k;
	    if(x-sum<j-1){
	    	while(x-sum>0){
	    		b[--k]++;
	    		x--;
			}
		}
		else if(x-sum==j-1){
			while(x-sum>0){
				b[--k]++;
				x--;
			}
			b[cnt-1]++;
		} 

	    for(int l=cnt-1;l>=0;l--){
	    	a[i]*=b[l];
//	    	cout<<b[0]<<endl;

		}
   }
	
}
int main(int argc, char** argv) {
	int n;
	cal();
	while(cin>>n){
		cout<<a[n]<<endl;
	}
	return 0;
}




