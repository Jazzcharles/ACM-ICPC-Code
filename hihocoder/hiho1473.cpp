#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int l,f,d;
		scanf("%d%d%d",&l,&f,&d);
		if(f>__gcd(d,l)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
} 
