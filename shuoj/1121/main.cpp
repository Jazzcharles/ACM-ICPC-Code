#include <bits/stdc++.h>
using namespace std;
int main(int argc, char** argv) {
	int i=1,n,ans=0;cin>>n;
	while(ans+i*i*i<=n){ans+=i*i*i;i++;}
	cout<<--i<<endl;
	return 0;
}
