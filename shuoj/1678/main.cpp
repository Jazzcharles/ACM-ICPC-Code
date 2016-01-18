#include <bits/stdc++.h>
using namespace std;
int a[101],b[101],c[202];
int main(int argc, char** argv) {
	int i,n,m,k;
	while(~scanf("%d%d%d",&n,&m,&k))
	{
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
			c[i]=a[i];
		}
		for(int j=0;j<m;j++){
			scanf("%d",&b[j]);
			c[i++]=b[j];
		}
		int l=m+n,cnt=1;
		sort(c,c+l);
//		for(int i=0;i<l;i++) cout<<c[i]<<' ';cout<<endl;
		for(i=1;i<l;i++){
			if(c[i]!=c[i-1]) cnt++;
			if(cnt==k) break;
		}
		cout<<c[i]<<endl;
	}
	return 0;
}
