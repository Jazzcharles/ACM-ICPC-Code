#include <iostream>
using namespace std;
int main(int argc, char** argv) {
	int n,m;
	while(cin>>m>>n)
	{
		long long j=0,o=0;
		for(int i=m;i<=n;i++)
		{
			if(i%2) j+=i*i*i;
			else o+=i*i;
		}
		cout<<o<<' '<<j<<endl;
	}
	return 0;
}
