#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int a[10005];
int main(){
	int n,x,s=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>a[i];
		s+=a[i];
	}
	sort(a+1,a+1+n);
	s=0;
	if(n&1){
		int num=a[n/2+1];
		for(int i=1;i<=n;i++){
			s+=abs(a[i]-num);
		}
		cout<<s<<endl;		
	}
	else{
		int num=(a[n/2]+a[n/2+1])>>1;
		for(int i=1;i<=n;i++){
			s+=abs(a[i]-num);
		}
		cout<<s<<endl;
	}

	return 0;
	
}
