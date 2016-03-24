#include<iostream>
using namespace std;
int gcd(int a,int b){
	if(!b) return a;
	else return gcd(b,a%b);
}
int main(){
	int x,y,cnt=0;
	cin>>x>>y;
	for(int i=x;i<=y;i+=x)
	{
		for(int j=i;j<=y;j+=x){
			if(gcd(i,j)==x&& i*j/x==y) {
			//	cout<<i<<' '<<j<<endl; 
				cnt++;
			}			
		}
	}
	cout<<cnt*2<<endl;
	return 0;
}
