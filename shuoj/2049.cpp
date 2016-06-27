#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;

double a[maxn];
int main(){
	int ca=1,n;
	while(cin>>n)
	{
		for(int i=0;i<n;i++) cin>>a[i];
		printf("Case %d: %.1f\n",ca++,*max_element(a,a+n));
	}
	return 0;
}
