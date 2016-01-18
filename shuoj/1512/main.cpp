#include <bits/stdc++.h>
#define lowbit(i) (i&(-i))
using namespace std;
const int maxn=1e5+5;
int bit[maxn],a[maxn],b[maxn],n;
void add(int i,int x){
	while(i<=n){
		bit[i]+=x;
		i+=lowbit(i);
	}
}

int query(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i-=lowbit(i);
	}
	return s;
}
int main(int argc, char** argv) {
	int ca=1;
	while(scanf("%d",&n)!=EOF){
		memset(bit,0,sizeof(bit));
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			b[i]=a[i];
		}
		sort(a,a+n);
		for(int i=0;i<n;i++){
			b[i]=lower_bound(a,a+n,b[i])-a+1;
		}
		int ans=0;
		for(int i=0;i<n;i++){
			ans+=i-query(b[i]);
			add(b[i],1);
		}
		printf("Case %d:\n",ca++);
		printf("%d\n",ans);
		cout<<endl;
	}



	return 0;
}
