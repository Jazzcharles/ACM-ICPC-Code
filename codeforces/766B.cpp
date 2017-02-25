#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+500;
int a[maxn]; 
int main() 
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	int f=0;
	for(int i=0;i<n-2;i++)
	{
		if(a[i]+a[i+1]>a[i+2])
			f=1;
	}
	if(f) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	
	return 0;
}
