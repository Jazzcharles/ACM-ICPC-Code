#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int a[maxn];
int b[maxn];
int f[maxn],ans,n,m,flag;
int fa[maxn],fb[maxn];


int main(){
	cin>>n;
	for(int i=0;i<n;++i) cin>>a[i];
	sort(a,a+n);
	cin>>m;
	for(int i=0;i<m;i++) cin>>b[i];
	sort(b,b+m);
	ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(f[j]) continue;
			if(abs(a[i]-b[j])<2){
				f[j]=1;
				ans++;
				break; 
			}
		}
	}
	cout<<ans<<endl;
	
	
	
	return 0;
}
/*
4
1 2 4 6 
5
1 5 5 7 9

2
1 10
1
9


1
4
5
1 2 3 5 5



4
1 1 2 3
1
4

*/
