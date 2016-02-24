#include<iostream>
using namespace std;

int main(){
	int n,x;
	cin>>n>>x;
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0,m=i;
		while(m){
			if(m%10==x) cnt++;
			m/=10;
		}
		ans+=cnt;
	}
	cout<<ans<<endl;
	return 0;
}
