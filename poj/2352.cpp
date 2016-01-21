#include <iostream>
using namespace std;
#define lowbit(i) (i&(-i))
const int maxn=1e5+5;
int bit[maxn],n,ans[maxn];
void add(int i,int x){
	while(i<=maxn){
		bit[i]+=x;
		i+=lowbit(i);
//		cout<<123<<endl;
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
	while(~scanf("%d",&n)){
		for(int i=0;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			++x;
			int level=query(x);
			ans[level]++;
			add(x,1);
		}
		for(int i=0;i<n;i++){
		 	printf("%d\n",ans[i]);
		}
	}
	return 0;
}
