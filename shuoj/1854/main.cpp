#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn],b[maxn],l[maxn],r[maxn];
int main(int argc, char** argv) {
	int k,n;
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);b[i]=a[i];
		}	
		scanf("%d",&k);
		sort(b,b+n);
		l[0]=0;
		for(int i=1;i<n;i++){
			l[i]=i*(b[i]-b[i-1]);
		}
		for(int i=n-1;i>=0;i--){
			r[i]=(n-i)*(b[i]-b[i-1]);
		}
		
		
	}
	return 0;
}
