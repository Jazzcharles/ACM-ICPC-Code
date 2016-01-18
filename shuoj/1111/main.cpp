#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
#define max(a,b) (a>b?a:b)
int main(int argc, char** argv) {
	int x,ans=-INF;
	while(cin>>x){
		if(x==-1) break;
		ans=max(x,ans);
	}
	cout<<ans<<endl;
	return 0;
}
