#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		ll n,m;
		scanf("%lld%lld",&n,&m);
		ll all=(n+n-1)/m, left=n/m, right=all-left;
		ll sum=(m+m*all)*all/2, suml=(m+left*m)*left/2, sumr=sum-suml;
		ll ans=0;
		if(m%2) ans=(suml-left)/2+right*n-sumr/2;
		else ans=(suml/2-left)+right*n-sumr/2;
		printf("%lld\n",ans);
	}
	return 0;
}
