#include<iostream>
using namespace std;
long long ans;
int main(){
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		ans+=i*i;
	}
	cout<<ans<<endl;
	return 0;
}
