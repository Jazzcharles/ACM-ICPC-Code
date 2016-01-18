#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	long long n,s=0,ans=1;
	cin>>n;
	for(int i=0;i<=n;i++)
	{
		if(!i) continue;
		ans*=i;
	}
	cout<<ans<<endl;
	return 0;
}
